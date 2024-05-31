
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "naloga1.h"

const int NASLEDNJE[] = {31, 68, 323, 170, 449, 42, 10, 537, 328, 104, 460, 168, 697, 215, 46, 27, 82, 351, 253, 151, 289, 329, 689, 510, 273, 175, 526, 572, 260, 134, 295, 119, 172, 459, 493, 467, 216, 551, 420, 692, 563, 395, 339, 421, 636, 189, 22, 133, 80, 81, 224, 14, 194, 47, 67, 576, 221, 619, 166, 302, 108, 257, 401, 258, 353, 378, 675, 591, 470, 644, 136, 356, 334, 255, 567, 284, 661, 370, 690, 682, 595, 16, 165, 348, 538, 17, 677, 169, 38, 259, 102, 310, 560, 21, 680, 465, 94, 489, 601, 457, 452, 392, 212, 605, 485, 205, 508, 226, 455, 650, 286, 240, 645, 202, 208, 399, 653, 272, 542, 398, 156, 28, 128, 270, 400, 546, 603, 268, 447, 109, 182, 303, 499, 23, 652, 480, 429, 628, 559, 505, 361, 4, 488, 577, 533, 256, 58, 627, 345, 325, 280, 569, 408, 336, 648, 371, 368, 140, 267, 694, 498, 446, 573, 161, 144, 126, 30, 159, 504, 623, 219, 541, 407, 685, 100, 693, 511, 545, 44, 50, 394, 98, 41, 145, 171, 293, 282, 430, 578, 32, 11, 196, 385, 278, 428, 445, 651, 453, 344, 74, 91, 66, 468, 667, 381, 338, 479, 358, 422, 211, 550, 252, 463, 698, 618, 625, 534, 629, 207, 626, 59, 410, 607, 372, 72, 543, 613, 490, 598, 656, 138, 62, 589, 450, 674, 321, 574, 125, 99, 437, 375, 414, 152, 473, 363, 426, 129, 269, 55, 360, 687, 350, 163, 658, 448, 291, 199, 611, 432, 477, 333, 320, 160, 624, 487, 330, 239, 364, 431, 679, 481, 218, 298, 409, 500, 529, 331, 335, 174, 70, 377, 562, 18, 671, 57, 137, 696, 492, 0, 346, 673, 180, 341, 236, 237, 406, 316, 666, 657, 177, 305, 580, 15, 86, 575, 411, 566, 634, 112, 191, 665, 588, 593, 646, 386, 229, 461, 243, 148, 383, 167, 233, 389, 617, 434, 123, 359, 88, 149, 552, 9, 518, 515, 299, 53, 699, 590, 110, 228, 688, 281, 76, 564, 204, 670, 355, 209, 555, 103, 132, 686, 416, 83, 322, 49, 154, 64, 294, 417, 6, 547, 558, 200, 90, 423, 181, 469, 107, 536, 277, 275, 309, 249, 640, 620, 340, 472, 367, 95, 176, 568, 388, 79, 582, 528, 117, 37, 668, 146, 130, 519, 276, 509, 155, 75, 527, 641, 639, 324, 659, 419, 262, 660, 458, 384, 631, 203, 512, 654, 435, 190, 514, 332, 655, 51, 150, 73, 242, 638, 635, 118, 691, 491, 676, 271, 13, 486, 376, 397, 244, 3, 609, 387, 633, 352, 162, 496, 318, 116, 96, 570, 33, 39, 7, 186, 597, 105, 319, 442, 69, 506, 131, 390, 649, 1, 266, 287, 357, 373, 311, 424, 35, 440, 326, 454, 317, 185, 579, 147, 34, 306, 179, 497, 263, 599, 586, 26, 540, 444, 530, 111, 594, 285, 585, 254, 36, 405, 369, 213, 443, 616, 300, 439, 220, 231, 188, 554, 539, 433, 681, 337, 61, 214, 532, 193, 247, 374, 54, 584, 78, 5, 456, 662, 404, 92, 365, 482, 695, 637, 264, 158, 503, 501, 234, 19, 314, 583, 246, 89, 366, 60, 153, 615, 402, 45, 313, 587, 621, 521, 502, 507, 347, 466, 548, 71, 412, 217, 312, 232, 251, 8, 425, 663, 248, 581, 56, 396, 296, 173, 610, 614, 683, 304, 678, 604, 571, 549, 315, 115, 288, 436, 12, 127, 622, 183, 513, 354, 474, 307, 106, 235, 349, 114, 475, 197, 413, 84, 198, 142, 606, 516, 556, 342, 608, 24, 164, 77, 238, 327, 274, 192, 642, 557, 525, 245, 664, 478, 265, 602, 143, 403, 517, 462, 113, 135, 93, 464, 292, 632, 495, 612, 343, 206, 201, 544, 643, 283, 48, 290, 279, 2, 178, 120, 535, 308, 438, 65, 40, 647, 250, 195, 427, 418, 63, 391, 141, 230, 52, 494, 222, 684, 157, 531, 87, 184, 476, 484, 101, 43, 362, 630, 227, 471, 139, 261, 669, 451, 124, 297, 596, 380, 97, 241, 520, 187, 672, 415, 122, 379, 20, 483, 522, 210, 592, 25, 85, 301, 29, 441, 561, 565, 223, 121, 393, 523, 600, 225, 553, 382};
const int PREJSNJE[] = {288, 454, 630, 430, 141, 510, 359, 443, 550, 330, 6, 190, 571, 425, 51, 302, 81, 85, 282, 524, 679, 93, 46, 133, 594, 684, 476, 15, 121, 687, 166, 0, 189, 441, 469, 461, 485, 386, 88, 442, 637, 182, 5, 658, 178, 534, 14, 53, 627, 354, 179, 414, 647, 334, 507, 248, 555, 284, 146, 220, 530, 501, 231, 643, 356, 636, 201, 54, 1, 449, 279, 544, 224, 416, 199, 394, 341, 596, 509, 382, 48, 49, 16, 352, 586, 685, 303, 653, 327, 528, 363, 200, 514, 615, 96, 378, 439, 671, 181, 238, 174, 657, 90, 348, 9, 446, 579, 367, 60, 129, 337, 480, 308, 613, 582, 568, 438, 385, 420, 31, 632, 692, 677, 325, 667, 237, 165, 572, 122, 246, 389, 451, 349, 47, 29, 614, 70, 285, 230, 663, 157, 645, 588, 609, 164, 183, 388, 468, 318, 328, 415, 19, 242, 531, 355, 393, 120, 651, 520, 167, 262, 163, 435, 252, 595, 82, 58, 320, 11, 87, 3, 184, 32, 558, 278, 25, 379, 299, 631, 471, 291, 365, 130, 574, 654, 466, 444, 674, 495, 45, 410, 309, 600, 504, 52, 640, 191, 584, 587, 256, 362, 623, 113, 406, 343, 105, 622, 218, 114, 346, 682, 209, 102, 488, 502, 13, 36, 546, 271, 170, 493, 56, 649, 691, 50, 696, 107, 661, 338, 315, 646, 494, 548, 321, 523, 580, 293, 294, 597, 266, 111, 672, 417, 317, 429, 604, 527, 505, 553, 372, 639, 549, 211, 18, 484, 73, 145, 61, 63, 89, 28, 664, 401, 473, 519, 607, 455, 158, 127, 247, 123, 424, 117, 24, 599, 370, 391, 369, 193, 629, 150, 340, 186, 626, 75, 482, 110, 456, 569, 20, 628, 255, 617, 185, 357, 30, 557, 668, 272, 333, 491, 686, 59, 131, 562, 300, 470, 578, 634, 371, 91, 459, 547, 535, 525, 567, 296, 465, 437, 447, 261, 235, 353, 2, 398, 149, 463, 598, 8, 21, 265, 276, 412, 260, 72, 277, 153, 500, 205, 42, 375, 292, 592, 621, 198, 148, 289, 541, 83, 581, 251, 17, 434, 64, 576, 345, 71, 457, 207, 326, 249, 140, 659, 244, 267, 515, 529, 377, 156, 487, 77, 155, 223, 458, 506, 240, 427, 280, 65, 678, 670, 204, 698, 319, 404, 192, 314, 432, 381, 322, 452, 644, 101, 693, 180, 41, 556, 428, 119, 115, 124, 62, 533, 610, 513, 486, 295, 172, 152, 273, 221, 305, 545, 585, 241, 676, 351, 358, 642, 400, 38, 43, 208, 364, 460, 551, 245, 641, 194, 136, 187, 268, 258, 498, 324, 409, 570, 239, 635, 492, 462, 688, 448, 489, 478, 195, 161, 128, 254, 4, 233, 666, 100, 197, 464, 108, 511, 99, 403, 33, 10, 316, 612, 212, 616, 95, 542, 35, 202, 366, 68, 662, 376, 243, 577, 583, 655, 259, 606, 206, 135, 270, 516, 680, 656, 104, 426, 264, 142, 97, 227, 422, 287, 34, 648, 619, 436, 472, 160, 132, 274, 522, 539, 521, 168, 139, 450, 540, 106, 392, 23, 176, 407, 575, 411, 332, 590, 611, 331, 390, 673, 538, 681, 694, 699, 603, 26, 395, 384, 275, 479, 652, 503, 144, 216, 633, 368, 7, 84, 497, 477, 171, 118, 225, 624, 177, 125, 360, 543, 566, 210, 37, 329, 697, 496, 347, 591, 602, 361, 138, 92, 689, 281, 40, 342, 690, 306, 74, 380, 151, 440, 565, 27, 162, 236, 304, 55, 143, 188, 467, 301, 554, 383, 526, 508, 483, 475, 536, 311, 232, 336, 67, 683, 312, 481, 80, 669, 445, 228, 474, 695, 98, 608, 126, 564, 103, 589, 222, 593, 431, 559, 257, 620, 226, 560, 532, 490, 323, 214, 57, 374, 537, 573, 169, 263, 215, 219, 147, 137, 217, 660, 405, 618, 433, 307, 419, 44, 518, 418, 397, 373, 396, 601, 625, 69, 112, 313, 638, 154, 453, 109, 196, 134, 116, 408, 413, 229, 298, 253, 399, 402, 76, 512, 552, 605, 310, 297, 203, 387, 665, 344, 283, 675, 290, 234, 66, 423, 86, 563, 269, 94, 499, 79, 561, 650, 173, 350, 250, 339, 22, 78, 421, 39, 175, 159, 517, 286, 12, 213};
const int RANDOM[] = {86, 389, 499, 160, 371, 110, 216, 317, 513, 228, 672, 542, 484, 436, 640, 166, 389, 134, 392, 526, 330, 95, 66, 264, 629, 277, 399, 465, 276, 354, 602, 592, 49, 367, 30, 443, 90, 150, 45, 444, 372, 601, 339, 162, 668, 245, 226, 390, 241, 439, 620, 198, 488, 174, 666, 370, 545, 416, 424, 123, 341, 653, 43, 74, 107, 155, 507, 457, 620, 219, 490, 86, 497, 564, 555, 221, 146, 196, 593, 71, 183, 193, 690, 354, 480, 79, 213, 352, 18, 561, 250, 670, 69, 694, 191, 137, 350, 661, 445, 462, 295, 278, 46, 450, 140, 9, 228, 91, 663, 105, 83, 452, 146, 376, 404, 589, 25, 34, 14, 296, 549, 355, 446, 172, 433, 516, 298, 97, 224, 462, 250, 10, 392, 287, 602, 308, 261, 436, 198, 452, 540, 38, 479, 172, 605, 348, 477, 544, 558, 52, 651, 690, 347, 604, 64, 249, 154, 153, 469, 39, 477, 288, 504, 608, 38, 123, 639, 45, 483, 633, 0, 275, 667, 281, 402, 458, 495, 27, 661, 416, 682, 196, 614, 14, 149, 111, 537, 128, 679, 522, 595, 286, 314, 109, 565, 434, 22, 313, 501, 168, 130, 327, 351, 254, 126, 1, 531, 434, 588, 357, 603, 413, 366, 522, 138, 11, 601, 587, 62, 388, 432, 680, 543, 340, 349, 368, 588, 674, 214, 398, 609, 564, 421, 149, 28, 19, 395, 72, 514, 277, 66, 120, 284, 136, 402, 25, 610, 65, 573, 654, 263, 599, 592, 305, 456, 414, 535, 378, 53, 694, 571, 548, 156, 253, 247, 525, 655, 20, 566, 466, 259, 457, 195, 24, 280, 520, 545, 655, 428, 440, 147, 17, 8, 267, 449, 568, 229, 65, 470, 90, 349, 406, 674, 86, 62, 587, 699, 315, 65, 517, 248, 191, 445, 237, 654, 646, 210, 530, 183, 287, 10, 649, 558, 255, 564, 447, 91, 297, 88, 664, 27, 518, 544, 621, 666, 517, 470, 492, 420, 375, 364, 298, 193, 84, 458, 316, 247, 200, 468, 442, 322, 305, 144, 60, 345, 231, 67, 312, 49, 394, 517, 564, 618, 375, 243, 603, 132, 696, 240, 533, 608, 388, 588, 325, 298, 326, 100, 319, 71, 247, 108, 264, 473, 189, 151, 114, 339, 308, 565, 538, 384, 502, 438, 445, 696, 345, 410, 535, 51, 309, 433, 529, 554, 179, 123, 31, 119, 65, 465, 503, 338, 338, 211, 175, 279, 308, 402, 512, 665, 193, 182, 95, 430, 440, 480, 70, 51, 38, 91, 168, 261, 57, 71, 90, 517, 416, 314, 238, 469, 436, 638, 353, 479, 349, 454, 146, 560, 413, 540, 256, 662, 306, 20, 694, 190, 360, 236, 141, 204, 603, 362, 445, 225, 159, 440, 421, 634, 67, 221, 69, 431, 273, 308, 582, 588, 536, 410, 282, 346, 370, 682, 261, 219, 245, 365, 449, 232, 650, 692, 467, 446, 89, 245, 12, 467, 482, 618, 107, 680, 302, 669, 380, 201, 96, 129, 566, 498, 307, 602, 138, 232, 170, 73, 217, 579, 405, 363, 411, 427, 7, 579, 45, 136, 203, 596, 11, 458, 120, 659, 304, 114, 597, 311, 364, 8, 2, 471, 592, 306, 446, 266, 334, 535, 79, 206, 293, 511, 556, 425, 369, 175, 550, 55, 502, 432, 524, 443, 471, 549, 293, 261, 674, 440, 58, 644, 427, 592, 585, 527, 139, 438, 216, 575, 489, 569, 4, 635, 275, 617, 672, 312, 662, 375, 269, 263, 639, 116, 373, 68, 516, 413, 305, 62, 664, 221, 549, 88, 250, 320, 65, 79, 83, 145, 562, 323, 562, 92, 395, 251, 359, 653, 640, 462, 81, 36, 201, 577, 359, 455, 655, 236, 346, 628, 589, 219, 208, 102, 103, 682, 90, 454, 214, 394, 105, 107, 299, 91, 159, 341, 547, 219, 119, 62, 39, 255, 211, 48, 386, 132, 295, 569, 692, 505, 341, 433, 137, 176, 417, 389, 393, 615, 290, 418, 121, 217, 587, 677, 52, 12, 141, 685, 7, 364, 142, 478, 47, 0, 642, 330, 600, 579, 14, 70, 64, 323, 56, 272, 260, 262, 569, 267, 590, 416, 475, 385, 297, 581, 115, 347, 115, 447, 206, 99, 525, 640, 288, 289, 381, 443};
const int N = sizeof(NASLEDNJE) / sizeof(NASLEDNJE[0]);
const int ZACETEK = 524;

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
