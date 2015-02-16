#include <stdio.h>

int main(void){
  int code[5] = { 539913291, 539767857 , 1769169250,  1918984819, 2125413 };
  int i = 0;
  
  /*for(i = 0; i < 5; i++){
    printf(" %d \n", itoa(code[i]));
  }*/
  
  printf(" %d ", itoa(code[2]));
  
  return 0;
}

/* win = 0;
      loss = 0;
      int matches = 0;
      float winp = 0;
      foreach (string s in l)
      {
        if(s.Contains("Mage"))
        {
          string pattern = @"[0-9]+";

          Match m = Regex.Match(s, pattern);
          win += Convert.ToInt32(m.Value);
          m = m.NextMatch();
          loss += Convert.ToInt32(m.Value);

          richTextBox2.Text += s + "\n";
        }
      }
      winp = ((float)win / ((float)win + (float)loss)) * 100;
      matches = win + loss;
      richTextBox2.Text += "\nTotal is "+ win + " wins and " + loss + " losses\n";
      richTextBox2.Text += "\nTotal matches is " + matches + " \n" + "Win percentage of " + winp.ToString("N") + " %\n"; */