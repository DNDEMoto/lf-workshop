因果ループ


同じリアクター内の、
1. リアクションは状態を共有しており、片方が実行するまで他方は実行できない
1. それぞれのリアクションは同一の論理時間に実行される。
1. 2つのリアクションが同一の論理時間トリガされる可能性があり、実行順の定義は必要
1. 同じ論理時間にトリガされる場合、実行順はコードの上から順に実行される。

ダイアグラムの番号はこれを表している

下記リアクションの順序を入れ替えるとエラーになる
```
    reaction(prompt) -> out {=
      // just counting
      self->count++;
      printf("%d. Hit Return or Enter!", self->count);
      fflush(stdout);
      lf_set(out, self->count);
    =}
  
    reaction(another) -> prompt {=
      // Schedule the next event. waiting sfor random time
      lf_schedule(prompt, additional_time(0, self->max_time - self->min_time));
    =}
```

なぜか？

万が一、GetUserInputのprompt入力と、ユーザーのキーボード入力が同時に起こる場合を考える

OKパターン

論理時間100:GetUserInputのpromptが入力される（２）★　prompt入力
論理時間100:RandomSourceのoutが出力される（２）　　prompt出力が同じ時間に起こる必要がある
論理時間100:GetUserInputのanotherが出力される（３）★　ユーザー入力
論理時間100:RandomSourceのanotherが入力される（３）ユーザー入力によってトリガされる

-> 矛盾なし

NGパターン

論理時間100:GetUserInputのpromptが入力される（２）★　prompt入力
論理時間100:RandomSourceのoutが出力される（３）　　　prompt出力が同じ時間に起こる必要がある
論理時間100:GetUserInputのanotherが出力される（３）★　ユーザー入力
論理時間100:RandomSourceのanotherが入力される（２）ユーザー入力によってトリガされる

３－＞２という順になって矛盾が生じる


