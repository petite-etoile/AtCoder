# ばしっと最適解が求まる
       if a_plus*a_minus < 0:
            break
        # 縮小!!! n/4本の直線を冗長と断定!!
        else:
            print("a_plus:", a_plus, "a_minus:", a_minus)
            if a_plus > 0:
                # ans_x > mid
                minus = False
                # print(a_plus,a_minus)

                delete_lines(minus, lines, x, line_pairs,exist_lines_index,mid)

            else:
                # ans_x > mid
                minus = True

                delete_lines(minus, lines, x, line_pairs,exist_lines_index,mid)
                pass
