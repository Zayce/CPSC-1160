int recursiveStrLen(string s, int l, int digitSum){
    if(l < 0){
        return digitSum;
    }
    else{
        if(s[l] >= '0' && s[l] <= '9'){
            return (recursiveStrLen(s, l - 1, digitSum + 1));
        }
        else{
            return recursiveStrLen(s, l - 1, digitSum);
        }
    }
}