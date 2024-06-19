
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "naloga1.h"

const int NASLEDNJE[] = {337, 9, 347, 596, 324, 294, 496, 509, 297, 756, 249, 38, 585, 406, 187, 614, 399, 439, 622, 129, 267, 20, 378, 255, 632, 277, 429, 778, 11, 477, 628, 121, 644, 759, 668, 359, 488, 24, 500, 784, 572, 137, 410, 89, 595, 702, 55, 350, 409, 623, 568, 226, 578, 694, 571, 781, 172, 219, 802, 738, 216, 779, 341, 342, 329, 262, 598, 136, 140, 408, 457, 722, 695, 43, 164, 774, 573, 142, 349, 261, 430, 44, 709, 201, 499, 594, 491, 316, 230, 49, 507, 494, 719, 396, 194, 382, 485, 46, 111, 469, 582, 197, 228, 173, 602, 618, 805, 531, 168, 713, 279, 21, 442, 584, 627, 280, 641, 303, 519, 454, 92, 200, 629, 315, 669, 407, 798, 443, 610, 268, 794, 223, 78, 724, 561, 309, 611, 672, 658, 284, 609, 298, 157, 746, 554, 356, 176, 292, 384, 35, 169, 536, 567, 210, 704, 657, 560, 482, 688, 48, 95, 139, 424, 243, 501, 514, 42, 687, 273, 528, 61, 306, 211, 247, 466, 240, 775, 420, 603, 696, 320, 236, 344, 245, 65, 604, 250, 127, 543, 706, 535, 290, 590, 391, 138, 653, 413, 53, 233, 490, 797, 524, 131, 272, 15, 791, 415, 512, 182, 67, 221, 612, 357, 202, 336, 118, 510, 220, 754, 800, 467, 649, 147, 679, 625, 685, 195, 728, 117, 789, 31, 158, 79, 583, 113, 680, 191, 416, 472, 697, 156, 39, 104, 636, 390, 402, 736, 177, 160, 50, 88, 96, 541, 660, 682, 616, 689, 224, 767, 471, 576, 677, 63, 16, 517, 626, 681, 527, 478, 171, 90, 296, 737, 47, 404, 765, 319, 664, 652, 654, 418, 93, 14, 419, 112, 134, 327, 256, 6, 241, 374, 229, 208, 529, 84, 62, 735, 205, 545, 487, 676, 107, 395, 505, 483, 170, 302, 180, 371, 651, 254, 592, 771, 126, 365, 313, 312, 375, 588, 712, 445, 539, 526, 184, 663, 639, 730, 122, 740, 260, 750, 325, 747, 518, 242, 305, 161, 368, 105, 723, 403, 77, 608, 373, 476, 503, 718, 807, 431, 441, 671, 81, 634, 103, 464, 101, 152, 174, 400, 310, 287, 85, 741, 340, 318, 128, 4, 597, 717, 787, 768, 58, 181, 484, 75, 508, 282, 333, 473, 776, 786, 462, 624, 426, 0, 520, 699, 385, 449, 265, 690, 398, 259, 479, 434, 673, 322, 179, 153, 148, 635, 123, 135, 569, 57, 346, 711, 175, 300, 433, 701, 707, 97, 548, 114, 745, 108, 725, 94, 432, 637, 562, 435, 330, 777, 619, 437, 684, 27, 647, 353, 450, 30, 427, 72, 362, 29, 481, 447, 804, 757, 453, 367, 397, 372, 150, 196, 796, 498, 752, 203, 411, 417, 795, 286, 405, 744, 412, 339, 587, 581, 761, 369, 766, 91, 739, 755, 334, 3, 246, 17, 414, 421, 360, 326, 686, 511, 321, 281, 493, 721, 589, 218, 606, 806, 354, 533, 646, 133, 438, 238, 705, 570, 394, 770, 143, 546, 553, 460, 335, 593, 386, 144, 190, 444, 83, 714, 19, 5, 217, 655, 188, 380, 18, 751, 475, 468, 186, 358, 227, 278, 258, 810, 492, 60, 470, 648, 650, 331, 620, 146, 463, 555, 656, 720, 521, 559, 37, 269, 667, 285, 387, 563, 389, 1, 729, 461, 51, 665, 40, 662, 515, 459, 743, 780, 630, 12, 364, 244, 607, 159, 537, 556, 727, 532, 266, 314, 580, 615, 189, 710, 116, 678, 23, 52, 167, 348, 425, 328, 361, 773, 670, 758, 586, 497, 749, 763, 480, 26, 276, 760, 455, 799, 317, 513, 73, 542, 489, 540, 45, 731, 141, 674, 401, 132, 289, 811, 551, 486, 207, 788, 332, 251, 683, 291, 383, 732, 599, 41, 448, 34, 446, 120, 552, 557, 283, 379, 234, 436, 32, 764, 734, 565, 538, 307, 525, 716, 130, 809, 2, 311, 193, 163, 237, 225, 659, 74, 642, 59, 566, 504, 270, 579, 145, 550, 124, 703, 558, 465, 631, 288, 621, 808, 66, 675, 231, 428, 523, 232, 22, 54, 36, 638, 199, 549, 355, 575, 393, 204, 82, 803, 106, 185, 782, 239, 149, 388, 68, 343, 698, 198, 742, 691, 7, 80, 100, 692, 376, 645, 70, 793, 661, 564, 801, 451, 516, 13, 125, 10, 666, 600, 252, 248, 345, 534, 99, 338, 748, 423, 253, 544, 76, 98, 456, 772, 301, 370, 783, 605, 522, 271, 474, 506, 693, 206, 708, 299, 56, 293, 110, 366, 102, 155, 295, 381, 392, 25, 151, 213, 643, 715, 547, 264, 452, 790, 154, 458, 613, 212, 214, 304, 785, 502, 178, 115, 352, 109, 323, 377, 192, 762, 263, 351, 274, 166, 495, 792, 633, 33, 183, 601, 640, 222, 87, 209, 275, 64, 574, 700, 530, 71, 162, 753, 86, 28, 215, 591, 577, 769, 235, 726, 8, 257, 363, 422, 119, 308, 617, 165, 69, 733};
const int PREJSNJE[] = {384, 544, 639, 468, 366, 508, 288, 693, 801, 1, 708, 28, 556, 706, 282, 204, 263, 470, 513, 507, 21, 111, 669, 573, 37, 746, 588, 428, 794, 436, 432, 230, 629, 778, 620, 149, 671, 537, 11, 241, 549, 618, 166, 73, 81, 599, 97, 273, 159, 89, 249, 547, 574, 197, 670, 46, 737, 404, 371, 648, 524, 170, 295, 262, 786, 184, 663, 209, 687, 809, 699, 790, 434, 595, 646, 374, 721, 341, 132, 232, 694, 351, 679, 505, 294, 361, 793, 783, 250, 43, 270, 464, 120, 281, 418, 160, 251, 412, 722, 715, 695, 355, 741, 353, 242, 338, 681, 301, 416, 766, 739, 98, 284, 234, 414, 764, 571, 228, 215, 805, 622, 31, 327, 401, 655, 707, 313, 187, 365, 19, 637, 202, 604, 488, 285, 402, 67, 41, 194, 161, 68, 601, 77, 495, 502, 653, 530, 222, 399, 685, 445, 747, 356, 398, 755, 742, 240, 142, 231, 560, 248, 336, 791, 642, 74, 808, 774, 575, 108, 150, 305, 269, 56, 103, 357, 407, 146, 247, 763, 397, 307, 372, 208, 779, 323, 682, 517, 14, 511, 569, 503, 236, 769, 641, 94, 226, 446, 101, 690, 673, 121, 83, 213, 450, 678, 297, 734, 609, 292, 784, 153, 172, 758, 748, 759, 795, 60, 509, 482, 57, 217, 210, 782, 131, 257, 644, 51, 519, 102, 291, 88, 665, 668, 198, 627, 799, 181, 643, 490, 684, 175, 289, 334, 163, 558, 183, 469, 173, 712, 10, 186, 612, 711, 719, 310, 23, 287, 802, 521, 392, 329, 79, 65, 771, 752, 389, 565, 20, 129, 538, 651, 730, 203, 168, 773, 785, 589, 25, 520, 110, 115, 478, 376, 625, 139, 540, 454, 360, 660, 605, 191, 614, 147, 738, 5, 743, 271, 8, 141, 736, 408, 725, 306, 117, 760, 335, 171, 634, 806, 135, 359, 640, 316, 315, 566, 123, 87, 593, 364, 276, 180, 477, 396, 767, 4, 331, 474, 286, 578, 64, 423, 528, 611, 377, 467, 499, 214, 0, 716, 458, 363, 62, 63, 688, 182, 713, 405, 2, 576, 78, 47, 772, 765, 430, 485, 675, 145, 212, 518, 35, 473, 579, 435, 803, 557, 314, 740, 442, 337, 462, 726, 308, 444, 343, 290, 317, 697, 768, 22, 626, 512, 744, 95, 615, 148, 387, 501, 541, 686, 543, 244, 193, 745, 677, 493, 302, 93, 443, 391, 16, 358, 603, 245, 340, 274, 455, 13, 125, 69, 48, 42, 451, 457, 196, 471, 206, 237, 452, 280, 283, 177, 472, 804, 718, 162, 577, 383, 433, 666, 26, 80, 348, 419, 409, 394, 422, 628, 426, 489, 17, 811, 349, 112, 127, 504, 320, 621, 438, 619, 388, 431, 704, 753, 441, 119, 591, 723, 70, 756, 552, 498, 546, 381, 531, 354, 658, 174, 220, 516, 99, 525, 259, 238, 378, 731, 515, 344, 29, 268, 393, 587, 437, 157, 304, 373, 96, 608, 299, 36, 597, 199, 86, 523, 479, 91, 775, 6, 584, 448, 84, 38, 164, 762, 345, 650, 303, 732, 90, 375, 7, 216, 476, 207, 594, 165, 551, 705, 264, 333, 118, 385, 535, 729, 667, 201, 635, 322, 267, 169, 293, 789, 107, 564, 486, 714, 190, 151, 561, 633, 321, 598, 252, 596, 188, 720, 298, 496, 751, 413, 674, 654, 607, 623, 497, 144, 532, 562, 624, 657, 536, 156, 134, 421, 542, 702, 632, 649, 152, 50, 403, 492, 54, 40, 76, 787, 676, 260, 797, 52, 652, 567, 460, 100, 233, 113, 12, 583, 459, 318, 481, 192, 796, 311, 500, 85, 44, 3, 367, 66, 617, 710, 780, 104, 178, 185, 728, 483, 559, 342, 140, 128, 136, 211, 757, 15, 568, 255, 807, 105, 425, 529, 661, 18, 49, 382, 224, 265, 114, 30, 122, 555, 659, 24, 777, 352, 400, 243, 420, 672, 325, 781, 116, 647, 749, 32, 698, 487, 429, 526, 221, 527, 309, 278, 195, 279, 510, 533, 155, 138, 645, 253, 701, 550, 324, 277, 548, 709, 539, 34, 124, 581, 350, 137, 395, 602, 664, 300, 261, 572, 223, 235, 266, 254, 613, 427, 225, 475, 167, 158, 256, 390, 692, 696, 733, 53, 72, 179, 239, 689, 386, 788, 410, 45, 656, 154, 491, 189, 411, 735, 82, 570, 406, 319, 109, 506, 750, 636, 368, 346, 92, 534, 480, 71, 339, 133, 417, 800, 563, 227, 545, 326, 600, 616, 810, 631, 296, 246, 272, 59, 465, 328, 362, 691, 553, 456, 415, 143, 332, 717, 585, 330, 514, 449, 792, 218, 466, 9, 440, 582, 33, 590, 461, 770, 586, 630, 275, 463, 258, 370, 798, 494, 312, 724, 580, 75, 176, 379, 424, 27, 61, 554, 55, 683, 727, 39, 761, 380, 369, 610, 229, 754, 205, 776, 700, 130, 453, 447, 200, 126, 592, 219, 703, 58, 680, 439, 106, 484, 347, 662, 638, 522};
const int RANDOM[] = {235, 694, 116, 655, 621, 544, 774, 525, 393, 468, 447, 578, 344, 515, 624, 397, 794, 639, 310, 297, 216, 404, 91, 104, 721, 37, 564, 523, 661, 205, 156, 616, 221, 202, 637, 536, 589, 1, 30, 133, 744, 250, 350, 726, 736, 701, 413, 798, 194, 227, 389, 419, 60, 458, 577, 1, 237, 758, 197, 177, 703, 413, 295, 730, 807, 292, 428, 770, 738, 345, 686, 30, 121, 446, 743, 357, 279, 765, 518, 747, 565, 553, 346, 311, 321, 257, 674, 707, 772, 692, 293, 520, 556, 357, 805, 542, 220, 83, 419, 472, 719, 565, 319, 239, 231, 803, 777, 189, 335, 4, 411, 454, 263, 134, 509, 500, 785, 654, 651, 577, 622, 764, 383, 168, 531, 724, 803, 201, 733, 606, 165, 385, 157, 690, 542, 98, 8, 518, 120, 778, 113, 390, 574, 329, 77, 403, 102, 463, 657, 35, 676, 535, 2, 772, 85, 309, 518, 582, 151, 194, 719, 368, 368, 42, 398, 805, 424, 160, 338, 754, 231, 451, 58, 461, 35, 770, 709, 258, 338, 464, 611, 690, 131, 384, 588, 643, 800, 98, 488, 229, 460, 494, 605, 457, 327, 160, 198, 34, 488, 668, 191, 768, 191, 411, 384, 701, 279, 485, 428, 136, 487, 228, 82, 145, 97, 697, 268, 793, 238, 550, 32, 449, 27, 601, 127, 58, 718, 715, 798, 810, 233, 754, 497, 469, 63, 175, 142, 673, 800, 717, 507, 309, 651, 773, 48, 269, 196, 799, 220, 317, 429, 496, 793, 252, 81, 120, 95, 616, 638, 416, 123, 576, 695, 220, 740, 355, 532, 271, 133, 286, 656, 609, 771, 63, 790, 707, 28, 529, 805, 602, 42, 689, 203, 270, 604, 551, 625, 732, 100, 13, 429, 129, 351, 619, 766, 563, 35, 690, 481, 184, 520, 669, 433, 659, 50, 205, 564, 789, 347, 712, 504, 459, 479, 511, 482, 497, 215, 121, 83, 73, 520, 789, 76, 156, 84, 11, 782, 398, 186, 761, 757, 353, 122, 11, 463, 240, 206, 791, 543, 592, 454, 332, 642, 378, 334, 235, 627, 73, 14, 278, 549, 648, 375, 775, 339, 437, 109, 226, 98, 737, 508, 258, 534, 288, 472, 388, 689, 332, 698, 748, 31, 383, 503, 201, 182, 743, 521, 139, 128, 723, 688, 103, 455, 617, 744, 583, 782, 242, 761, 395, 383, 440, 551, 782, 530, 104, 445, 275, 546, 268, 276, 680, 697, 559, 431, 480, 619, 292, 687, 547, 680, 359, 807, 76, 778, 556, 544, 351, 608, 260, 158, 733, 551, 771, 659, 14, 234, 12, 646, 549, 534, 372, 454, 219, 777, 714, 211, 288, 244, 295, 538, 590, 188, 200, 757, 95, 635, 213, 412, 94, 715, 372, 613, 415, 321, 448, 124, 327, 637, 435, 324, 628, 22, 621, 515, 563, 541, 612, 377, 335, 142, 706, 326, 467, 810, 756, 19, 564, 605, 800, 67, 257, 465, 200, 379, 49, 404, 747, 725, 158, 773, 545, 661, 314, 58, 435, 731, 208, 127, 516, 63, 91, 315, 736, 801, 505, 226, 16, 376, 106, 185, 142, 138, 499, 648, 139, 95, 303, 286, 56, 740, 35, 362, 275, 53, 432, 167, 64, 48, 320, 96, 232, 372, 334, 338, 747, 588, 230, 58, 325, 391, 210, 206, 265, 137, 474, 321, 360, 611, 517, 709, 581, 95, 785, 222, 23, 173, 745, 209, 591, 586, 810, 650, 760, 616, 613, 731, 188, 723, 448, 587, 19, 147, 788, 416, 801, 777, 17, 228, 494, 71, 450, 580, 162, 768, 435, 185, 198, 486, 218, 316, 697, 482, 2, 780, 417, 627, 618, 99, 299, 791, 598, 50, 541, 779, 560, 517, 683, 125, 659, 565, 270, 279, 449, 54, 363, 740, 73, 29, 493, 490, 740, 745, 754, 346, 438, 332, 724, 392, 225, 310, 685, 268, 368, 486, 80, 648, 301, 808, 678, 386, 190, 619, 463, 615, 429, 554, 611, 188, 794, 716, 753, 798, 399, 51, 497, 676, 383, 501, 521, 312, 269, 26, 61, 360, 563, 544, 179, 498, 660, 523, 584, 647, 464, 18, 79, 761, 764, 325, 68, 651, 273, 402, 227, 433, 634, 356, 48, 349, 62, 610, 567, 347, 590, 21, 501, 315, 717, 164, 355, 222, 107, 94, 797, 136, 779, 415, 581, 738, 57, 277, 32, 294, 755, 534, 547, 465, 42, 428, 757, 78, 331, 200, 390, 558, 270, 25, 287, 3, 756, 455, 619, 738, 204, 584, 31, 510, 491, 381, 100, 59, 98, 743, 510, 493, 563, 41, 400, 107, 248, 255, 653, 210, 743, 212, 706, 172, 630, 14, 47, 360, 428, 349, 118, 39, 640, 239, 687, 296, 648, 692, 208, 193, 154, 115, 774, 327, 1, 570, 787, 553, 774, 150, 367, 257, 150, 505, 31, 414, 533, 415, 297, 148, 425, 554, 291, 665, 350, 18, 265, 224, 182, 460, 782, 114, 543, 403, 553, 21, 335, 5};
const int N = sizeof(NASLEDNJE) / sizeof(NASLEDNJE[0]);
const int ZACETEK = 440;

int main() {
    Vozlisce** v = calloc(N + 1, sizeof(Vozlisce*));
    for (int i = 0; i < N; i++) {
        v[i] = calloc(1, sizeof(Vozlisce));
    }

    for (int i = 0; i < N; i++) {
        v[i]->naslednje = v[NASLEDNJE[i]];
        v[i]->prejsnje = v[RANDOM[i]];
    }

    nastavi(v[ZACETEK]);

    for (int i = 0; i < N; i++) {
        printf("%d", v[i]->naslednje == v[NASLEDNJE[i]]);
    }
    printf("\n");

    for (int i = 0; i < N; i++) {
        printf("%d", v[i]->prejsnje == v[PREJSNJE[i]]);
    }
    printf("\n");

    for (int i = 0; i < N; i++) {
        free(v[i]);
    }
    free(v);

    return 0;
}