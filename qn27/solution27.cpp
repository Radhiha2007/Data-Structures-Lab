#include <cstdio>
#include <cstring>

int main() {
    int testcase;
    printf("Enter the number of testcases:\n");
    scanf("%d", &testcase);

    while (testcase--) {
        int n;
        printf("Enter the total number of words:\n");
        scanf("%d", &n);
        
        char player1[n][4];
        char player2[n][4];
        char player3[n][4];

        // Read words for each player
        printf("Player 1:\n");
        for (int i = 0; i < n; i++) {
            scanf("%s", player1[i]);
        }

        printf("Player 2:\n");
        for (int i = 0; i < n; i++) {
            scanf("%s", player2[i]);
        }

        printf("Player 3:\n");
        for (int i = 0; i < n; i++) {
            scanf("%s", player3[i]);
        }

        // Scores for each player
        int score[3] = {0, 0, 0};
        int count1 = 0, count2 = 0, count3 = 0;
        // Check uniqueness of words
        for (int i = 0; i < n; i++) {
    count1 = 1, count2 = 1, count3 = 1;

    // Count how many players have player1[i]
    for (int j = 0; j < n; j++) {
        if (strcmp(player1[i], player2[j]) == 0 || strcmp(player1[i], player3[j]) == 0)
            count1++;
    }
    if (count1 == 1) score[0] += 3;
    else if (count1 == 2) score[0] += 1;

    // Count how many players have player2[i]
    for (int j = 0; j < n; j++) {
        if (strcmp(player2[i], player1[j]) == 0 || strcmp(player2[i], player3[j]) == 0)
            count2++;
    }
    if (count2 == 1) score[1] += 3;
    else if (count2 == 2) score[1] += 1;

    // Count how many players have player3[i]
    for (int j = 0; j < n; j++) {
        if (strcmp(player3[i], player1[j]) == 0 || strcmp(player3[i], player2[j]) == 0)
            count3++;
    }
    if (count3 == 1) score[2] += 3;
    else if (count3 == 2) score[2] += 1;
}
        // Print results
        printf("The score for Player 1: %d\n", score[0]);
        printf("The score for Player 2: %d\n", score[1]);
        printf("The score for Player 3: %d\n", score[2]);
    }

    return 0;
}
