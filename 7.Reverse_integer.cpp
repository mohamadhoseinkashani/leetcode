//this is a solution to the question "Reverse integer".
class Solution {
public:
    int reverse(int x) {
        if ( x < 10 && x > -10){return x;}   //if the number has only one digit return value would be itself.
        if(x == INT_MIN){return 0;}          //the constraints were numbers from [-2^31 , 2^31 - 1].
        int hold = abs(x);                   //this variable turns negetive numbers to positive so only half of the constraints are needed to be reversed.
      
        int reverse = 0;
        int m = int(log10(hold)) + 1;        //this variable holds the number of digits in a number ex:if number is 365 there are 3 digits in the number.
      
        if(m == 10){                         //this if statement checks if the LSD is bigger than 2 zero would be returned.(becuse if LSD is bigger than 2 an integer could not hold it).                
            if(hold % 10 > 2){ 
                return 0;
            }
        }
        int max = INT_MAX;
        for(int i = 0; i < m; ++i){          //this loop trys to reverse the number but it also checks out that the reverse number could fit inside 4 bytes of integer datatype.
            int l = pow(10 , m - i - 1);

            max -= (l * (hold % 10));
            if(max <= 0){return 0;}
            reverse += l * (hold % 10);
            hold = int(hold / 10);
        }
        return (reverse * (abs(x) / x));    //this is the return value which is multiplyed by the ratio of the x and its absolute value.(returns "-reverse" if x is negetive).
    }
};
