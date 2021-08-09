#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Max number of candidates
#define MAX 9

// preferences[i][j] is number of voters who prefer i over j
int preferences[MAX][MAX];

// locked[i][j] means i is locked in over j
bool locked[MAX][MAX];

// Each pair has a winner, loser
typedef struct
{
    int winner;
    int loser;
}
pair;

// Array of candidates
string candidates[MAX];
pair pairs[MAX * (MAX - 1) / 2];

int pair_count;
int candidate_count;
int pcount = 0;

// Function prototypes
bool vote(int rank, string name, int ranks[]);
void record_preferences(int ranks[]);
void add_pairs(void);
void sort_pairs(void);
void lock_pairs(void);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: tideman [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i] = argv[i + 1];
    }

    // Clear graph of locked in pairs
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            locked[i][j] = false;
        }
    }

    pair_count = 0;
    int voter_count = get_int("Number of voters: ");

    // Query for votes
    for (int i = 0; i < voter_count; i++)
    {
        // ranks[i] is voter's ith preference
        int ranks[candidate_count];

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            if (!vote(j, name, ranks))
            {
                printf("Invalid vote.\n");
                return 3;
            }
        }
        record_preferences(ranks);

        printf("\n");
    }

    add_pairs();
    sort_pairs();
    lock_pairs();
    print_winner();
    return 0;
}

// Update ranks given a new vote
bool vote(int rank, string name, int ranks[])
{
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(candidates[i], name) == 0)
        {
            for (int n = 0; n < rank; n++)
            {
                if (ranks[n] == i)
                {
                    return false;
                    break;
                }
            }
            ranks[rank] = i;
            return true;
            break;
        }
    }
    return false;
}

// Update preferences given one voter's ranks
void record_preferences(int ranks[])
{
    for (int n = 0; n < candidate_count; n++)
    {
        for (int i = n + 1; i < candidate_count; i++)
        {
            preferences[ranks[n]][ranks[i]]++;
        }
    }
}

// Record pairs of candidates where one is preferred over the other
void add_pairs(void)
{
    for (int n = 0; n < candidate_count; n++)
    {
        for (int i = n + 1; i < candidate_count; i++)
        {
            pair_count++;
            
            if (preferences[n][i] == preferences[i][n])
            {
                pair_count--;
            }
        }
    }

    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            if ((preferences[i][j] != 0) && (preferences[j][i] < preferences[i][j]))
            {
                pairs[pcount].winner = i;
                pairs[pcount].loser = j;
                pcount++;
            }
        }
    }
}

int check(const void *a, const void *b)
{
    pair *checka = (pair *)a;
    pair *checkb = (pair *)b;
    int arr[4] = {checka->winner, checka->loser, checkb->winner, checkb->loser};

    return (preferences[arr[2]][arr[3]] - preferences[arr[0]][arr[1]]);
}

// Sort pairs in decreasing order by strength of victory
void sort_pairs(void)
{
    qsort(pairs, pair_count, sizeof(pair), check);
}


bool cyclec(int win, int los)
{
    if (locked[los][win] == true)
    {
        return true;
    }
    
    for (int i = 0; i < pair_count; i++)
    {
        if (locked[los][i])
        {
            if (cyclec(win, i))
            {
                return true;
            }
        }
    }
    
    return false;
}

// Lock pairs into the candidate graph in order, without creating cycles
void lock_pairs(void)
{
    for (int i = 0; i < pair_count; i++)
    {
        int a = pairs[i].winner;
        int b = pairs[i].loser;
        
        if (cyclec(a, b) == false)
        {
            locked[a][b] = true;
        }
    }
}

bool source_check(int s)
{
    for (int i = 0; i < candidate_count; i++)
    {
        if (locked[i][s] == true)
        {
            return false;
        }
    }
    return true;
}

int takesource()
{
    for (int i = 0; i < candidate_count; i++)
    {
        if (source_check(i))
        {
            return i;
        }
    }
    return -1;
}

// Print the winner of the election
void print_winner(void)
{
    int i = takesource();
    if (i != -1)
    {
        printf("%s\n", candidates[i]);
    }
}