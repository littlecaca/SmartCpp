/*
 * To be effective at low-level programming or debugging
 * you need to understand that every high-level concept 
 * eventually maps to this low-level model, 
 * and learning how the mapping works will help you.
 */

typedef struct Data
{
    int num;
    char *name;
    int count;
} Data;

Data get_data() {
    Data d1 = {1, 0, 32};
    return d1;
}

int main() {
    Data d2 = get_data();
    int n = d2.num;

}