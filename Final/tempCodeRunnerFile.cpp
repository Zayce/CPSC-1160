   cout << "number of elements n = 0\n";
   {
      int n = 0;
      char A[] = {'a', 'b', 'c'};
      char ch = 'x';
      int occs = 0;
      cout << hasAL(A, n, ch, occs) << endl; // 1
   }

   {
      int n = 0;
      char A[] = {'a', 'b', 'c'};
      char ch = 'x';
      int occs = 3;
      cout << hasAL(A, n, ch, occs) << endl; // 0
   }

   {
      int n = 0;
      char A[] = {'a', 'b', 'c'};
      char ch = 'a';
      ch = 'a';
      int occs = 1;
      cout << hasAL(A, n, ch, occs) << endl; // 0
   }

   cout << "no occurrences\n";
   {
      int n = 3;
      char A[] = {'a', 'b', 'c'};
      char ch = 'a';
      int occs = 0;
      cout << hasAL(A, n, ch, occs) << endl; // 1
   }

   {
      int n = 3;
      char A[] = {'a', 'b', 'c'};
      char ch = 'x';
      int occs = 0;
      cout << hasAL(A, n, ch, occs) << endl; // 1
   }