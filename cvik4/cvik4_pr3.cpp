#include <iostream>
using namespace std;

class AudioClip
{
private:
    int *samples;
    int size;

public:
    AudioClip()
    {
        size = 0;
        samples = nullptr;
    }
    AudioClip(int count, int values[])
    {
        size = count;
        samples = new int[count];
        for (int i = 0; i < count; i++)
        {
            samples[i] = values[i];
        }
    }
    ~AudioClip()
    {
        delete[] samples;
    }
    AudioClip(const AudioClip &other)
    {
        size = other.size;
        samples = new int[size];
        for (int i = 0; i < size; i++)
        {
            samples[i] = other.samples[i];
        }
    }
    AudioClip &operator=(const AudioClip &other)
    {
        if (this == &other)
            return *this;
        else
        {
            delete[] samples;
            samples = nullptr;

            size = other.size;
            samples = new int[size];
            for (int i = 0; i < size; i++)
            {
                samples[i] = other.samples[i];
            }
        }
        return *this;
    }
    int getSize()
    {
        return size;
    }
    int &operator[](int index)
    {
        return samples[index];
    }
    friend ostream &operator<<(ostream &output, const AudioClip &clip)
    {
        if (clip.size == 0)
        {
            output << "(empty)";
        }
        else
        {
            for (int i = 0; i < clip.size; i++)
            {
                if (i > 0)
                {
                    output << " " << clip.samples[i];
                }
                else
                {
                    output << clip.samples[i];
                }
            }
        }
        return output;
    }
};

AudioClip reversed(AudioClip clip)
{
    if (clip.getSize() == 0)
        return AudioClip();
    if (clip.getSize() == 1)
    {
        return clip;
    }
    int s = clip.getSize();
    int *temp_arr = new int[s];

    for (int i = 0; i < s; i++)
    {
        temp_arr[i] = clip[s - 1 - i];
    }
    AudioClip reversed(s, temp_arr);
    delete[] temp_arr;

    return reversed;
}

int main()
{
    int n;
    cin >> n;
    if (n < 0 || n > 100)
    {
        cout << "Invalid count" << endl;
        return 1;
    }
    int *sample = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> sample[i];
        while (sample[i] < -1000 || sample[i] > 1000)
        {
            cout << "Not in the range. Type one more time: ";
            cin >> sample[i];
        }
    }
    int replacement;
    cin >> replacement;
    if (replacement < -1000 || replacement > 1000)
    {
        cout << "Invalid count" << endl;
        return 1;
    }
    AudioClip original(n, sample);
    delete[] sample;
    AudioClip copy = original;
    if (copy.getSize() > 0)
        copy[0] = replacement;
    int value = -1;
    AudioClip assigned(1, &value);
    assigned = copy;
    if (copy.getSize() > 0)
        copy[0] = 0;
    assigned = assigned;
    AudioClip backward = reversed(original);

    cout << "Original: " << original << endl;
    cout << "Copy: " << copy << endl;
    cout << "Assigned: " << assigned << endl;
    cout << "Reversed: " << backward << endl;

    return 0;
}