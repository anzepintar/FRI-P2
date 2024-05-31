#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 10240

void print_usage(const char *prog_name) {
    printf("Usage: %s <input_file> <output_file> <m> <column_names...>\n", prog_name);
}

int main(int argc, char *argv[]) {
    if (argc < 5) {
        print_usage(argv[0]);
        return 1;
    }

    char *input_file = argv[1];
    char *output_file = argv[2];
    int m = atoi(argv[3]);
    char **selected_columns = argv + 4;
    int num_selected_columns = argc - 4;

    FILE *infile = fopen(input_file, "r");
    if (!infile) {
        perror("Error opening input file");
        return 1;
    }

    FILE *outfile = fopen(output_file, "w");
    if (!outfile) {
        perror("Error opening output file");
        fclose(infile);
        return 1;
    }

    char line[MAX_LINE_LENGTH];
    char *headers[MAX_LINE_LENGTH / 2];
    int column_indices[MAX_LINE_LENGTH / 2];

    // Read the header line
    if (!fgets(line, sizeof(line), infile)) {
        perror("Error reading header line");
        fclose(infile);
        fclose(outfile);
        return 1;
    }

    int header_count = 0;
    char *token = strtok(line, " \n");
    while (token) {
        headers[header_count++] = token;
        token = strtok(NULL, " \n");
    }

    // Determine the indices of the selected columns
    for (int i = 0; i < num_selected_columns; i++) {
        column_indices[i] = -1;
        for (int j = 0; j < header_count; j++) {
            if (strcmp(selected_columns[i], headers[j]) == 0) {
                column_indices[i] = j;
                break;
            }
        }
        if (column_indices[i] == -1) {
            fprintf(stderr, "Error: Column '%s' not found in header\n", selected_columns[i]);
            fclose(infile);
            fclose(outfile);
            return 1;
        }
    }

    // Write the selected headers to the output file
    for (int i = 0; i < num_selected_columns; i++) {
        fprintf(outfile, "%s", selected_columns[i]);
        if (i < num_selected_columns - 1) {
            fprintf(outfile, ",");
        }
    }
    fprintf(outfile, "\n");

    // Process the rest of the file
    while (fgets(line, sizeof(line), infile)) {
        char *columns[MAX_LINE_LENGTH / 2];
        int column_count = 0;
        token = strtok(line, " \n");
        while (token) {
            columns[column_count++] = token;
            token = strtok(NULL, " \n");
        }

        for (int i = 0; i < num_selected_columns; i++) {
            fprintf(outfile, "%s", columns[column_indices[i]]);
            if (i < num_selected_columns - 1) {
                fprintf(outfile, ",");
            }
        }
        fprintf(outfile, "\n");
    }

    fclose(infile);
    fclose(outfile);

    return 0;
}

