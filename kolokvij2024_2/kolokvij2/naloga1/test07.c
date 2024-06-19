
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "naloga1.h"

const int NASLEDNJE[] = {291, 524, 214, 2, 179, 334, 460, 269, 532, 364, 387, 170, 433, 84, 385, 30, 514, 528, 520, 145, 480, 157, 522, 504, 467, 199, 267, 540, 437, 101, 530, 392, 8, 478, 299, 289, 53, 288, 268, 207, 173, 86, 353, 304, 27, 457, 253, 174, 465, 216, 295, 274, 249, 197, 438, 17, 130, 234, 181, 302, 141, 318, 134, 148, 193, 434, 213, 379, 277, 473, 155, 208, 491, 171, 395, 168, 222, 293, 20, 436, 146, 412, 158, 205, 281, 80, 78, 512, 260, 113, 58, 37, 13, 46, 72, 324, 506, 15, 18, 426, 307, 360, 16, 292, 40, 400, 389, 309, 408, 230, 388, 118, 56, 94, 132, 439, 140, 160, 541, 164, 99, 341, 282, 462, 489, 21, 519, 354, 404, 150, 451, 273, 1, 331, 415, 215, 314, 441, 357, 52, 219, 19, 297, 272, 508, 347, 196, 191, 159, 285, 36, 136, 106, 386, 242, 545, 511, 194, 432, 163, 77, 336, 244, 38, 503, 452, 114, 493, 69, 495, 144, 414, 209, 510, 28, 112, 463, 240, 210, 416, 60, 349, 228, 62, 257, 346, 442, 190, 166, 48, 342, 427, 105, 128, 204, 312, 394, 380, 484, 373, 536, 109, 298, 162, 45, 51, 424, 402, 151, 359, 337, 488, 315, 283, 430, 326, 75, 50, 280, 138, 218, 381, 279, 471, 81, 425, 175, 358, 3, 184, 330, 263, 447, 220, 102, 59, 68, 421, 154, 156, 116, 41, 108, 413, 100, 278, 369, 104, 543, 65, 320, 82, 339, 32, 245, 338, 264, 262, 461, 450, 422, 340, 250, 322, 147, 368, 153, 276, 79, 63, 455, 466, 328, 64, 31, 239, 73, 26, 445, 505, 115, 515, 362, 266, 256, 449, 516, 119, 398, 477, 435, 275, 348, 468, 55, 476, 459, 300, 149, 420, 517, 538, 259, 186, 91, 43, 411, 246, 286, 127, 177, 203, 470, 261, 384, 247, 237, 139, 110, 42, 311, 176, 485, 531, 251, 137, 523, 350, 90, 229, 95, 399, 374, 310, 323, 188, 406, 57, 284, 142, 301, 11, 313, 472, 355, 258, 0, 221, 370, 482, 486, 456, 378, 33, 475, 464, 306, 231, 183, 223, 418, 407, 325, 271, 446, 248, 235, 226, 396, 498, 372, 212, 10, 71, 167, 535, 76, 296, 454, 124, 352, 192, 97, 182, 89, 371, 534, 423, 308, 200, 419, 225, 98, 351, 126, 185, 211, 499, 332, 474, 121, 367, 361, 410, 333, 444, 479, 103, 202, 428, 85, 111, 6, 125, 527, 254, 319, 189, 93, 365, 233, 409, 393, 270, 500, 265, 135, 403, 87, 236, 227, 317, 129, 487, 492, 123, 405, 165, 376, 401, 54, 316, 255, 483, 66, 133, 49, 533, 224, 507, 509, 70, 375, 344, 12, 345, 152, 241, 440, 67, 294, 243, 529, 513, 327, 23, 195, 397, 217, 7, 539, 5, 25, 161, 497, 287, 363, 24, 490, 172, 305, 232, 496, 521, 391, 117, 303, 39, 178, 35, 356, 525, 343, 61, 518, 34, 29, 187, 238, 180, 542, 22, 390, 329, 481, 366, 469, 74, 494, 290, 96, 122, 448, 201, 453, 9, 458, 107, 206, 252, 501, 88, 131, 537, 382, 526, 44, 120, 502, 4, 443, 143, 321, 198, 429, 335, 169, 377, 47, 431, 383, 14, 417, 83, 92};
const int PREJSNJE[] = {346, 132, 3, 228, 529, 471, 412, 469, 32, 515, 372, 341, 454, 92, 541, 97, 102, 55, 98, 141, 78, 125, 501, 465, 477, 472, 277, 44, 174, 496, 15, 274, 253, 353, 495, 489, 150, 91, 163, 487, 104, 241, 319, 305, 526, 204, 93, 538, 189, 446, 217, 205, 139, 36, 440, 294, 112, 337, 90, 235, 180, 493, 183, 269, 273, 249, 444, 459, 236, 168, 451, 373, 94, 276, 507, 216, 376, 160, 86, 268, 85, 224, 251, 543, 13, 410, 41, 428, 521, 384, 328, 304, 544, 418, 113, 330, 510, 382, 392, 120, 244, 29, 234, 407, 247, 192, 152, 517, 242, 201, 318, 411, 175, 89, 166, 280, 240, 485, 111, 287, 527, 400, 511, 435, 379, 413, 394, 309, 193, 432, 56, 522, 114, 445, 62, 426, 151, 325, 219, 317, 116, 60, 339, 531, 170, 19, 80, 264, 63, 298, 129, 208, 456, 266, 238, 70, 239, 21, 82, 148, 117, 473, 203, 159, 119, 437, 188, 374, 75, 536, 11, 73, 479, 40, 47, 226, 321, 310, 488, 4, 499, 58, 383, 358, 229, 395, 303, 497, 335, 417, 187, 147, 381, 64, 157, 466, 146, 53, 533, 25, 389, 513, 408, 311, 194, 83, 518, 39, 71, 172, 178, 396, 371, 66, 2, 135, 49, 468, 220, 140, 233, 347, 76, 359, 448, 391, 367, 430, 182, 329, 109, 357, 481, 420, 57, 366, 429, 316, 498, 275, 177, 457, 154, 461, 162, 254, 307, 315, 365, 52, 262, 324, 519, 46, 415, 442, 284, 184, 345, 302, 88, 313, 257, 231, 256, 425, 283, 26, 38, 7, 423, 363, 143, 131, 51, 291, 267, 68, 245, 222, 218, 84, 122, 213, 338, 149, 308, 475, 37, 35, 509, 0, 103, 77, 460, 50, 377, 142, 202, 34, 297, 340, 59, 486, 43, 480, 356, 100, 388, 107, 333, 320, 195, 342, 136, 212, 441, 431, 61, 416, 250, 532, 263, 334, 95, 362, 215, 464, 272, 503, 230, 133, 398, 404, 5, 535, 161, 210, 255, 252, 261, 121, 190, 492, 453, 455, 185, 145, 292, 181, 327, 393, 380, 42, 127, 344, 490, 138, 227, 209, 101, 402, 282, 476, 9, 419, 505, 401, 265, 246, 348, 385, 370, 199, 332, 452, 438, 537, 352, 67, 197, 221, 524, 540, 314, 14, 153, 10, 110, 106, 502, 484, 31, 422, 196, 74, 368, 467, 288, 331, 105, 439, 207, 427, 128, 436, 336, 361, 108, 421, 403, 306, 81, 243, 171, 134, 179, 542, 360, 390, 299, 237, 260, 387, 206, 225, 99, 191, 409, 534, 214, 539, 158, 12, 65, 290, 79, 28, 54, 115, 458, 137, 186, 530, 405, 278, 364, 232, 512, 285, 259, 130, 165, 514, 378, 270, 351, 45, 516, 296, 6, 258, 123, 176, 355, 48, 271, 24, 293, 506, 312, 223, 343, 69, 399, 354, 295, 289, 33, 406, 20, 504, 349, 443, 198, 322, 350, 433, 211, 124, 478, 72, 434, 167, 508, 169, 482, 474, 369, 397, 424, 520, 528, 164, 23, 279, 96, 449, 144, 450, 173, 156, 87, 463, 16, 281, 286, 300, 494, 126, 18, 483, 22, 326, 1, 491, 525, 414, 17, 462, 30, 323, 8, 447, 386, 375, 200, 523, 301, 470, 27, 118, 500, 248, 545};
const int RANDOM[] = {365, 371, 536, 297, 295, 315, 358, 182, 474, 176, 504, 26, 540, 240, 498, 266, 455, 528, 104, 526, 517, 218, 434, 288, 153, 479, 163, 436, 516, 394, 58, 368, 200, 75, 367, 484, 507, 67, 501, 339, 487, 472, 243, 280, 197, 494, 99, 458, 110, 126, 260, 472, 74, 388, 10, 433, 124, 70, 416, 411, 29, 230, 514, 4, 226, 96, 193, 420, 49, 204, 163, 238, 54, 396, 306, 433, 45, 296, 252, 456, 99, 175, 102, 468, 155, 29, 389, 144, 112, 270, 528, 97, 241, 13, 538, 241, 458, 36, 479, 93, 172, 477, 282, 143, 97, 88, 383, 269, 533, 404, 383, 191, 250, 509, 38, 435, 244, 451, 436, 300, 45, 339, 219, 535, 319, 75, 128, 475, 276, 494, 166, 445, 324, 82, 30, 219, 102, 140, 506, 142, 388, 89, 160, 136, 24, 206, 224, 322, 386, 426, 499, 340, 29, 465, 389, 393, 511, 412, 301, 20, 6, 13, 65, 498, 171, 77, 434, 491, 162, 31, 16, 383, 541, 175, 121, 73, 118, 351, 469, 62, 459, 375, 232, 219, 390, 280, 451, 231, 361, 46, 79, 307, 190, 326, 384, 168, 193, 68, 378, 504, 375, 293, 78, 522, 239, 182, 62, 375, 391, 207, 455, 545, 320, 256, 8, 364, 293, 454, 380, 6, 486, 426, 531, 65, 307, 93, 443, 99, 359, 260, 63, 106, 500, 314, 303, 368, 285, 96, 230, 440, 282, 160, 530, 255, 231, 328, 359, 223, 317, 158, 233, 113, 327, 289, 396, 453, 26, 128, 176, 299, 319, 136, 189, 387, 98, 95, 344, 192, 299, 513, 173, 295, 386, 141, 343, 23, 30, 355, 399, 368, 283, 535, 239, 271, 237, 171, 48, 418, 494, 403, 214, 288, 450, 330, 61, 449, 1, 222, 378, 287, 384, 17, 437, 455, 408, 502, 483, 265, 355, 479, 397, 37, 9, 409, 58, 2, 84, 318, 166, 472, 370, 333, 318, 352, 1, 505, 271, 429, 183, 179, 410, 342, 523, 339, 159, 259, 223, 503, 8, 359, 510, 78, 116, 446, 174, 198, 215, 225, 48, 339, 384, 239, 236, 303, 506, 513, 370, 249, 153, 65, 66, 328, 454, 400, 253, 253, 163, 253, 288, 412, 89, 291, 277, 529, 183, 68, 242, 362, 224, 48, 226, 469, 59, 164, 526, 34, 54, 36, 31, 287, 270, 484, 257, 310, 308, 421, 345, 414, 397, 169, 459, 480, 213, 221, 4, 375, 386, 433, 253, 226, 240, 316, 19, 247, 205, 50, 307, 429, 447, 216, 136, 497, 512, 299, 5, 359, 104, 156, 417, 516, 370, 175, 224, 43, 13, 434, 300, 208, 225, 91, 358, 244, 106, 508, 542, 9, 228, 41, 252, 508, 543, 312, 383, 5, 88, 103, 453, 352, 129, 154, 398, 214, 460, 167, 166, 473, 444, 127, 245, 121, 465, 457, 64, 363, 136, 463, 454, 155, 91, 86, 16, 391, 389, 189, 156, 160, 331, 2, 83, 67, 330, 526, 535, 291, 5, 402, 372, 61, 7, 67, 81, 114, 143, 20, 394, 382, 61, 288, 437, 426, 403, 518, 382, 495, 315, 251, 34, 542, 378, 65, 30, 92, 217, 116, 537, 202, 69, 218, 55, 193, 6, 256, 493, 26, 316, 321, 411, 28, 415, 491, 492, 134, 24, 496, 248};
const int N = sizeof(NASLEDNJE) / sizeof(NASLEDNJE[0]);
const int ZACETEK = 544;

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