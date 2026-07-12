int findComplement(int num) {
    int ans[32];
    int i=0;
    while (num>0){
        int quo=num/2;
        int rem=num%2;
        num=quo;
        ans[i]=rem;
        i++;
    }
    for (int j = 0; j < i; j++) {
        if (ans[j] == 1)
            ans[j] = 0;
        else
            ans[j] = 1;
    }
    int count = 0;
    int power = 1;

    for (int j = 0; j < i; j++) {
        count = count + (ans[j] * power);
        if (j != i - 1)
            power = power * 2;
    }

    return count;
}
