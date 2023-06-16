#include "assemble.h"
#include <stdlib.h>
#include <printf.h>

int main(int argc, char **argv) {
//  char str[] = "ldr x20, [x5, #8]";
//  ArrayList *tokens = tokenize(str);
//  print_ArrayList_elements(tokens);

  char line[] = "ldr x1 [x2]!";
  int number_of_lines = 1;
  char **lines =
      malloc(number_of_lines * sizeof(char *)); //readLines(file_name);
  lines[0] = line;
  ArrayList *token_lines = create_ArrayList(NULL, &free_ArrayList);
  for (int i = 0; i < number_of_lines; i++) {// maybe works
    ArrayList *tokens = tokenize(lines[i]);
    add_ArrayList_element(token_lines, tokens);
      print_ArrayList_elements(tokens);
  }
  free(lines);
  TreeMap *label_identifiers = first_pass(token_lines);
  ArrayList *trees = second_pass(token_lines, label_identifiers);
  free_ArrayList(token_lines);
  free_map(label_identifiers);
  // TODO: Make second_pass return an ArrayList
  // TODO: Use the parser trees to create machine code
  free_ArrayList(trees);
  return EXIT_SUCCESS;
}
