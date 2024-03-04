from manim_imports_ext import *

class CountingScene(Scene):
    CONFIG = {
        "base" : 10,
        "power_colors" : [YELLOW, MAROON_B, RED, GREEN, BLUE, PURPLE_D],
        "counting_dot_starting_position" : (FRAME_X_RADIUS-1)*RIGHT + (FRAME_Y_RADIUS-1)*UP,
        "count_dot_starting_radius" : 0.5,
        "dot_configuration_height" : 2,
        "ones_configuration_location" : UP+2*RIGHT,
        "num_scale_factor" : 2,
        "num_start_location" : 2*DOWN,
    }
    def setup(self):
        self.dots = VGroup()
        self.number = 0        
        self.number_mob = VGroup(OldTex(str(self.number)))
        self.number_mob.scale(self.num_scale_factor)
        self.number_mob.shift(self.num_start_location)
        self.digit_width = self.number_mob.get_width()

        self.initialize_configurations()
        self.arrows = VGroup()
        self.add(self.number_mob)

    def get_template_configuration(self):
        #This should probably be replaced for non-base-10 counting scenes
        down_right = (0.5)*RIGHT + (np.sqrt(3)/2)*DOWN
        result = []
        for down_right_steps in range(5):
            for left_steps in range(down_right_steps):
                result.append(
                    down_right_steps*down_right + left_steps*LEFT
                )
        return reversed(result[:self.base])

    def get_dot_template(self):
        #This should be replaced for non-base-10 counting scenes
        down_right = (0.5)*RIGHT + (np.sqrt(3)/2)*DOWN
        dots = VGroup(*[
            Dot(
                point, 
                radius = 0.25,
                fill_opacity = 0,
                stroke_width = 2,
                stroke_color = WHITE,
            )
            for point in self.get_template_configuration()
        ])
        dots[-1].set_stroke(width = 0)
        dots.set_height(self.dot_configuration_height)
        return dots

    def initialize_configurations(self):
        self.dot_templates = []
        self.dot_template_iterators = []
        self.curr_configurations = []

    def add_configuration(self):
        new_template = self.get_dot_template()
        new_template.move_to(self.ones_configuration_location)
        left_vect = (new_template.get_width()+LARGE_BUFF)*LEFT
        new_template.shift(
            left_vect*len(self.dot_templates)
        )
        self.dot_templates.append(new_template)
        self.dot_template_iterators.append(
            it.cycle(new_template)
        )
        self.curr_configurations.append(VGroup())

    def count(self, max_val, run_time_per_anim = 1):
        for x in range(max_val):
            self.increment(run_time_per_anim)

    def increment(self, run_time_per_anim = 1, added_anims = [], total_run_time = None):
        run_all_at_once = (total_run_time is not None)
        if run_all_at_once:
            num_rollovers = self.get_num_rollovers()
            run_time_per_anim = float(total_run_time)/(num_rollovers+1)
        moving_dot = Dot(
            self.counting_dot_starting_position,
            radius = self.count_dot_starting_radius,
            color = self.power_colors[0],
        )
        moving_dot.generate_target()
        moving_dot.set_fill(opacity = 0)

        continue_rolling_over = True
        place = 0
        self.number += 1
        added_anims = list(added_anims) #Silly python objects...
        added_anims += self.get_new_configuration_animations()
        while continue_rolling_over:          
            moving_dot.target.replace(
                next(self.dot_template_iterators[place])
            )
            if run_all_at_once:
                denom = float(num_rollovers+1)
                start_t = place/denom
                def get_modified_rate_func(anim):
                    return lambda t : anim.original_rate_func(
                        start_t + t/denom
                    )
                for anim in added_anims:
                    if not hasattr(anim, "original_rate_func"):
                        anim.original_rate_func = anim.rate_func
                    anim.rate_func = get_modified_rate_func(anim)
            self.play(
                MoveToTarget(moving_dot), 
                *added_anims, 
                run_time = run_time_per_anim
            )
            self.curr_configurations[place].add(moving_dot)
            if not run_all_at_once:
                added_anims = []


            if len(self.curr_configurations[place].split()) == self.base:
                full_configuration = self.curr_configurations[place]
                self.curr_configurations[place] = VGroup()
                place += 1
                center = full_configuration.get_center_of_mass()
                radius = 0.6*max(
                    full_configuration.get_width(),
                    full_configuration.get_height(),
                )
                circle = Circle(
                    radius = radius,
                    stroke_width = 0,
                    fill_color = self.power_colors[place],
                    fill_opacity = 0.5,
                )
                circle.move_to(center)
                moving_dot = VGroup(circle, full_configuration)
                moving_dot.generate_target()
                moving_dot[0].set_fill(opacity = 0)
            else:
                continue_rolling_over = False
        self.play(*self.get_digit_increment_animations())

    def get_new_configuration_animations(self):
        if self.is_perfect_power():
            self.add_configuration()
            return [FadeIn(self.dot_templates[-1])]
        else:
            return []

    def get_digit_increment_animations(self):
        result = []
        new_number_mob = self.get_number_mob(self.number)
        new_number_mob.move_to(self.number_mob, RIGHT)
        if self.is_perfect_power():
            place = len(new_number_mob.split())-1
            arrow = Arrow(
                new_number_mob[place].get_top(),
                self.dot_templates[place].get_bottom(),
                color = self.power_colors[place]
            )
            self.arrows.add(arrow)
            result.append(ShowCreation(arrow))
        result.append(Transform(
            self.number_mob, new_number_mob,
            lag_ratio = 0.5
        ))
        return result

    def get_number_mob(self, num):
        result = VGroup()
        place = 0
        while num > 0:
            digit = OldTex(str(num % self.base))
            if place >= len(self.power_colors):
                self.power_colors += self.power_colors
            digit.set_color(self.power_colors[place])
            digit.scale(self.num_scale_factor)
            digit.move_to(result, RIGHT)
            digit.shift(place*(self.digit_width+SMALL_BUFF)*LEFT)
            result.add(digit)
            num /= self.base
            place += 1
        return result

    def is_perfect_power(self):
        number = self.number
        while number > 1:
            if number%self.base != 0:
                return False
            number /= self.base
        return True

    def get_num_rollovers(self):
        next_number = self.number + 1
        result = 0
        while next_number%self.base == 0:
            result += 1
            next_number /= self.base
        return result

class BinaryCountingScene(CountingScene):
    CONFIG = {
        "base" : 2,
        "dot_configuration_height" : 1,
        "ones_configuration_location" : UP+5*RIGHT
    }
    def get_template_configuration(self):
        return [ORIGIN, UP]

class CountInDecimal(CountingScene):
    def construct(self):
        for x in range(11):
            self.increment()
        for x in range(85):
            self.increment(0.25)
        for x in range(20):
            self.increment()

class CountInTernary(CountingScene):
    CONFIG = {
        "base" : 3,
        "dot_configuration_height" : 1,
        "ones_configuration_location" : UP+4*RIGHT
    }
    def construct(self):
        self.count(27)

    # def get_template_configuration(self):
    #     return [ORIGIN, UP]

class CountTo27InTernary(CountInTernary):
    def construct(self):
        for x in range(27):
            self.increment()
        self.wait()

class CountInBinaryTo256(BinaryCountingScene):
    def construct(self):
        self.count(256, 0.25)

class TowersOfHanoiScene(Scene):
    CONFIG = {
        "disk_start_and_end_colors" : [BLUE_E, BLUE_A],
        "num_disks" : 5,
        "peg_width" : 0.25,
        "peg_height" : 2.5,
        "peg_spacing" : 4,
        "include_peg_labels" : True,
        "middle_peg_bottom" : 0.5*DOWN,
        "disk_height" : 0.4,
        "disk_min_width" : 1,
        "disk_max_width" : 3,
        "default_disk_run_time_off_peg" : 1,
        "default_disk_run_time_on_peg" : 2,
    }
    def setup(self):
        self.add_pegs()
        self.add_disks()

    def add_pegs(self):
        peg = Rectangle(
            height = self.peg_height,
            width = self.peg_width, 
            stroke_width = 0,
            fill_color = GREY_BROWN,
            fill_opacity = 1,
        )
        peg.move_to(self.middle_peg_bottom, DOWN)
        self.pegs = VGroup(*[
            peg.copy().shift(vect)
            for vect in (self.peg_spacing*LEFT, ORIGIN, self.peg_spacing*RIGHT)
        ])
        self.add(self.pegs)
        if self.include_peg_labels:
            self.peg_labels = VGroup(*[
                OldTex(char).next_to(peg, DOWN)
                for char, peg in zip("ABC", self.pegs)
            ])
            self.add(self.peg_labels)

    def add_disks(self):
        self.disks = VGroup(*[
            Rectangle(
                height = self.disk_height,
                width = width,
                fill_color = color,
                fill_opacity = 0.8,
                stroke_width = 0,
            )
            for width, color in zip(
                np.linspace(
                    self.disk_min_width, 
                    self.disk_max_width,
                    self.num_disks
                ),
                color_gradient(
                    self.disk_start_and_end_colors,
                    self.num_disks
                )
            )
        ])
        for number, disk in enumerate(self.disks):
            label = OldTex(str(number))
            label.set_color(BLACK)
            label.set_height(self.disk_height/2)
            label.move_to(disk)
            disk.add(label)
            disk.label = label
        self.reset_disks(run_time = 0)

        self.add(self.disks)

    def reset_disks(self, **kwargs):
        self.disks.generate_target()
        self.disks.target.arrange(DOWN, buff = 0)
        self.disks.target.move_to(self.pegs[0], DOWN)
        self.play(
            MoveToTarget(self.disks), 
            **kwargs
        )
        self.disk_tracker = [
            set(range(self.num_disks)),
            set([]),
            set([])
        ]

    def disk_index_to_peg_index(self, disk_index):
        for index, disk_set in enumerate(self.disk_tracker):
            if disk_index in disk_set:
                return index
        raise Exception("Somehow this disk wasn't accounted for...")

    def min_disk_index_on_peg(self, peg_index):
        disk_index_set = self.disk_tracker[peg_index]
        if disk_index_set:
            return min(self.disk_tracker[peg_index])
        else:
            return self.num_disks

    def bottom_point_for_next_disk(self, peg_index):
        min_disk_index = self.min_disk_index_on_peg(peg_index)
        if min_disk_index >= self.num_disks:
            return self.pegs[peg_index].get_bottom()
        else:
            return self.disks[min_disk_index].get_top()

    def get_next_disk_0_peg(self):
        curr_peg_index = self.disk_index_to_peg_index(0)
        return (curr_peg_index+1)%3

    def get_available_peg(self, disk_index):
        if disk_index == 0:
            return self.get_next_disk_0_peg()
        for index in range(len(list(self.pegs))):
            if self.min_disk_index_on_peg(index) > disk_index:
                return index
        raise Exception("Tower's of Honoi rule broken: No available disks")

    def set_disk_config(self, peg_indices):
        assert(len(peg_indices) == self.num_disks)
        self.disk_tracker = [set([]) for x in range(3)]
        for n, peg_index in enumerate(peg_indices):
            disk_index = self.num_disks - n - 1
            disk = self.disks[disk_index]
            peg = self.pegs[peg_index]
            disk.move_to(peg.get_bottom(), DOWN)
            n_disks_here = len(self.disk_tracker[peg_index])
            disk.shift(disk.get_height()*n_disks_here*UP)
            self.disk_tracker[peg_index].add(disk_index)

    def move_disk(self, disk_index, **kwargs):
        next_peg_index = self.get_available_peg(disk_index)
        self.move_disk_to_peg(disk_index, next_peg_index, **kwargs)

    def move_subtower_to_peg(self, num_disks, next_peg_index, **kwargs):
        disk_indices = list(range(num_disks))
        peg_indices = list(map(self.disk_index_to_peg_index, disk_indices))
        if len(set(peg_indices)) != 1:
            warnings.warn("These disks don't make up a tower right now")
        self.move_disks_to_peg(disk_indices, next_peg_index, **kwargs)

    def move_disk_to_peg(self, disk_index, next_peg_index, **kwargs):
        self.move_disks_to_peg([disk_index], next_peg_index, **kwargs)

    def move_disks_to_peg(self, disk_indices, next_peg_index, run_time = None, stay_on_peg = True, added_anims = []):
        if run_time is None:
            if stay_on_peg is True:
                run_time = self.default_disk_run_time_on_peg
            else:
                run_time = self.default_disk_run_time_off_peg
        disks = VGroup(*[self.disks[index] for index in disk_indices])
        max_disk_index = max(disk_indices)
        next_peg = self.pegs[next_peg_index]        
        curr_peg_index = self.disk_index_to_peg_index(max_disk_index)
        curr_peg = self.pegs[curr_peg_index]
        if self.min_disk_index_on_peg(curr_peg_index) != max_disk_index:
            warnings.warn("Tower's of Hanoi rule broken: disk has crap on top of it")
        target_bottom_point = self.bottom_point_for_next_disk(next_peg_index)
        path_arc = np.sign(curr_peg_index-next_peg_index)*np.pi/3
        if stay_on_peg:
            self.play(
                Succession(
                    ApplyMethod(disks.next_to, curr_peg, UP, 0),
                    ApplyMethod(disks.next_to, next_peg, UP, 0, path_arc = path_arc),
                    ApplyMethod(disks.move_to, target_bottom_point, DOWN),
                ),
                *added_anims,
                run_time = run_time,
                rate_func = lambda t : smooth(t, 2)
            )
        else:
            self.play(
                ApplyMethod(disks.move_to, target_bottom_point, DOWN),
                *added_anims,
                path_arc = path_arc*2,
                run_time = run_time,
                rate_func = lambda t : smooth(t, 2)
            )
        for disk_index in disk_indices:
            self.disk_tracker[curr_peg_index].remove(disk_index)
            self.disk_tracker[next_peg_index].add(disk_index)

class ConstrainedTowersOfHanoiScene(TowersOfHanoiScene):
    def get_next_disk_0_peg(self):
        if not hasattr(self, "total_disk_0_movements"):
            self.total_disk_0_movements = 0
        curr_peg_index = self.disk_index_to_peg_index(0)        
        if (self.total_disk_0_movements/2)%2 == 0:
            result = curr_peg_index + 1
        else:
            result = curr_peg_index - 1
        self.total_disk_0_movements += 1
        return result

def get_ruler_sequence(order = 4):
    if order == -1:
        return []
    else:
        smaller = get_ruler_sequence(order - 1)
        return smaller + [order] + smaller

def get_ternary_ruler_sequence(order = 4):
    if order == -1:
        return []
    else:
        smaller = get_ternary_ruler_sequence(order-1)
        return smaller+[order]+smaller+[order]+smaller

class SolveHanoi(TowersOfHanoiScene):
    def construct(self):
        self.wait()
        for x in get_ruler_sequence(self.num_disks-1):
            self.move_disk(x, stay_on_peg = False)
        self.wait()

class SolveConstrainedHanoi(ConstrainedTowersOfHanoiScene):
    def construct(self):
        self.wait()
        for x in get_ternary_ruler_sequence(self.num_disks-1):
            self.move_disk(x, run_time = 0.5, stay_on_peg = False)
        self.wait()

class Keith(PiCreature):
    CONFIG = {
        "color" : GREEN_D
    }

def get_binary_tex_mobs(num_list):
    result = VGroup()
    zero_width = OldTex("0").get_width()
    nudge = zero_width + SMALL_BUFF
    for num in num_list:
        bin_string = bin(num)[2:]#Strip off the "0b" prefix
        bits = VGroup(*list(map(Tex, bin_string)))
        for n, bit in enumerate(bits):
            bit.shift(n*nudge*RIGHT)
        bits.move_to(ORIGIN, RIGHT)
        result.add(bits)
    return result

def get_base_b_tex_mob(number, base, n_digits):
    assert(number < base**n_digits)
    curr_digit = n_digits - 1
    zero = OldTex("0")
    zero_width = zero.get_width()
    zero_height = zero.get_height()
    result = VGroup()
    for place in range(n_digits):
        remainder = number%base
        digit_mob = OldTex(str(remainder))
        digit_mob.set_height(zero_height)
        digit_mob.shift(place*(zero_width+SMALL_BUFF)*LEFT)
        result.add(digit_mob)
        number = (number - remainder)/base
    return result.center()

def get_binary_tex_mob(number, n_bits = 4):
    return get_base_b_tex_mob(number, 2, n_bits)

def get_ternary_tex_mob(number, n_trits = 4):
    return get_base_b_tex_mob(number, 3, n_trits)


####################

class IntroduceKeith(Scene):
    def construct(self):
        morty = Mortimer(mode = "happy")
        keith = Keith(mode = "dance_kick")
        keith_image = ImageMobject("keith_schwarz", invert = False)
        # keith_image = Rectangle()
        keith_image.set_height(FRAME_HEIGHT - 2)
        keith_image.next_to(ORIGIN, LEFT)
        keith.move_to(keith_image, DOWN+RIGHT)
        morty.next_to(keith, buff = LARGE_BUFF, aligned_edge = DOWN)
        morty.make_eye_contact(keith)
        randy = Randolph().next_to(keith, LEFT, LARGE_BUFF, aligned_edge = DOWN)
        randy.shift_onto_screen()

        bubble = keith.get_bubble(SpeechBubble, width = 7)
        bubble.write("01101011 $\\Rightarrow$ Towers of Hanoi")
        zero_width = bubble.content[0].get_width()
        one_width = bubble.content[1].get_width()        
        for mob in bubble.content[:8]:
            if abs(mob.get_width() - zero_width) < 0.01:
                mob.set_color(GREEN)
            else:
                mob.set_color(YELLOW)

        bubble.resize_to_content()
        bubble.pin_to(keith)
        VGroup(bubble, bubble.content).shift(DOWN)

        randy.bubble = randy.get_bubble(SpeechBubble, height = 3)
        randy.bubble.write("Wait, what's \\\\ Towers of Hanoi?")

        title = OldTexText("Keith Schwarz (Computer scientist)")
        title.to_edge(UP)

        self.add(keith_image, morty)
        self.play(Write(title))
        self.play(FadeIn(keith, run_time = 2))
        self.play(FadeOut(keith_image), Animation(keith))
        self.play(Blink(morty))
        self.play(
            keith.change_mode, "speaking",
            keith.set_height, morty.get_height(),
            keith.next_to, morty, LEFT, LARGE_BUFF,
            run_time = 1.5
        )
        self.play(
            ShowCreation(bubble),
            Write(bubble.content)
        )
        self.play(
            morty.change_mode, "pondering",
            morty.look_at, bubble
        )
        self.play(Blink(keith))
        self.wait()
        original_content = bubble.content
        bubble.write("I'm usually meh \\\\ on puzzles")
        self.play(
            keith.change_mode, "hesitant",
            Transform(original_content, bubble.cont