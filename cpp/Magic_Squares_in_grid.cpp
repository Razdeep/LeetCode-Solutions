/**
 *  https://leetcode.com/problems/magic-squares-in-grid/
 */
// Note this just a part of the code, hence it wont execute

class Solution
{
  public:
    bool valid(vector<int> &flattened_vector)
    {
        // First check that whether all the elements are distinct or not
        std::vector<int> count_list(10, 0);
        for (int this_element : flattened_vector)
        {
            if (this_element >= 1 && this_element <= 9)
                count_list[this_element]++;
        }
        
        // Checking all elements exists and unique
        for (int index=1; index<=9 ; index++)
            if (count_list[index] != 1)
                return false;

        // Designating the elements [Optional]
        int a = flattened_vector[0];
        int b = flattened_vector[1];
        int c = flattened_vector[2];
        int d = flattened_vector[3];
        int e = flattened_vector[4];
        int f = flattened_vector[5];
        int g = flattened_vector[6];
        int h = flattened_vector[7];
        int i = flattened_vector[8];

        return (a + b + c + d + e + f + g + h + i == 45) &&
               (a + b + c == 15) &&
               (d + e + f == 15) &&
               (g + h + i == 15) &&
               (a + d + g == 15) &&
               (b + e + h == 15) &&
               (c + f + i == 15) &&
               (a + e + i == 15) &&
               (c + e + g == 15);
    }
    int numMagicSquaresInside(vector<vector<int>> &grid)
    {
        int count = 0;
        //int grid_rows_length = grid.size()/grid[0].size();
        int grid_rows_length = grid.size();
        int grid_columns_length = grid[0].size();
        vector<int> flattened_vector;
        for (int r = 0; r < grid_rows_length - 2; r++)
        {
            for (int c = 0; c < grid_columns_length - 2; c++)
            {
                
                flattened_vector.clear();
                flattened_vector.push_back(grid[r][c]);
                flattened_vector.push_back(grid[r][c + 1]);
                flattened_vector.push_back(grid[r][c + 2]);
                flattened_vector.push_back(grid[r + 1][c]);
                flattened_vector.push_back(grid[r + 1][c + 1]);
                flattened_vector.push_back(grid[r + 1][c + 2]);
                flattened_vector.push_back(grid[r + 2][c]);
                flattened_vector.push_back(grid[r + 2][c + 1]);
                flattened_vector.push_back(grid[r + 2][c + 2]);
                
                if (valid(flattened_vector))
                    count++;
            }
        }
        return count;
    }
};