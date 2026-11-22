// func set_stats_consumer_bit_mask @ 006729c8 size=56

void set_stats_consumer_bit_mask(int param_1,int param_2)

{
  if (param_2 == 0) {
    if (param_1 == 1) {
      stats_consumer_bit_mask = stats_consumer_bit_mask | 1;
      return;
    }
    stats_consumer_bit_mask = stats_consumer_bit_mask & 0xfffffffe;
  }
  return;
}

