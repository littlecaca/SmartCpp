
// The global static variable count has extern link attribute.
int count = 32;
// This will lead to a warning, becasue extern indicates it
// is not a definition
// extern double price = 2.33;
double price = 2.33;

// The const object is defined local to the file by default,
// so we add the extern qualifier.
extern const int height = 175;

