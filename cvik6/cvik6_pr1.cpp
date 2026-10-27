#include <iostream>
using namespace std;

class Recipe{
    private:
        int portions;
        int counts;
        int grams[5];
    public:
        Recipe(): counts(0), portions(1){
            for (int i = 0; i < 5; i++) {
                grams[i] = 0;
            }
        }
        Recipe(int p, int n, int values[]): portions(p), counts(n) {
            for (int i = 0; i < n; i++) {
                grams[i] = values[i];
            }
            for (int i = n; i < 5; i ++ ){
                grams[i] = 0;
            }
        }
        int getPortions()
        {
            return portions;
        }
        int getCount() {
            return counts;
        }
        int getGrams(int index) {
            return grams[index];
        }
        void setPortions(int p) {
            portions = p;
        }
        int &operator[](int index) {
            return grams[index];
        }
        friend ostream &operator<<(ostream &out,
                                   const Recipe &recipe);
};

Recipe forGuests(Recipe recipe, int guests)
{
    int oldPortions = recipe.getPortions();

    for (int i = 0; i < recipe.getCount(); i++)
    {
        if (recipe[i] != 0)
        {
            recipe[i] = (recipe[i] * guests + oldPortions - 1) / oldPortions;
        }
    }

    recipe.setPortions(guests);
    return recipe;
}

void forGuests(Recipe &recipe, int guests, Recipe &result)
{
    int values[5] = {};

    for (int i = 0; i < recipe.getCount(); i++)
    {
        int grams = recipe.getGrams(i);

        if (grams != 0)
        {
            values[i] = (grams * guests + recipe.getPortions() - 1) / recipe.getPortions();
        }
    }

    Recipe updated(guests, recipe.getCount(), values);
    result = updated;
}

bool canPrepare(Recipe &recipe, int stock[], int count)
{
    if (count != recipe.getCount())
    {
        return false;
    }

    for (int i = 0; i < count; i++)
    {
        if (stock[i] < recipe[i])
        {
            return false;
        }
    }

    return true;
}
std::ostream &operator<<(std::ostream &out, const Recipe &recipe) {
    out << recipe.portions << " |";
    if(recipe.counts == 0) {
        out << " -";
    }
    else {
        for (int i = 0; i < recipe.counts; i++)
        {
            out << " " << recipe.grams[i];
        }
    }
    
    return out;
}

int main() {
    int n, portions, guests, secondguest;
    cin >> n >> portions >> guests >> secondguest;
    int values[5] = {};
    int stock[5] = {};

    for (int i = 0; i < n; i++)
    {
        cin >> values[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> stock[i];
    }
    Recipe original(portions, n, values);
    Recipe first = forGuests(original, guests);

    Recipe second;
    forGuests(original, secondguest, second);

    cout << "Original: " << original << '\n';
    cout << "First: " << first << '\n';

    cout << "First ready: "
         << (canPrepare(first, stock, n) ? "yes" : "no")
         << '\n';

    cout << "Second: " << second << '\n';

    return 0;
}