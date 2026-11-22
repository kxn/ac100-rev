// func reset_stats_db_rd_sample @ 00667df0 size=60

void reset_stats_db_rd_sample(int param_1)

{
  if (param_1 != 0) {
    *(undefined1 *)(param_1 + 0x48) = 0;
    *(undefined1 *)(param_1 + 100) = 0;
    *(undefined1 *)(param_1 + 0x11) = 0xff;
    *(undefined1 *)(param_1 + 0x31) = 0xff;
    *(undefined1 *)(param_1 + 0x32) = 0xff;
    *(undefined1 *)(param_1 + 0x12) = 0xff;
    *(undefined1 *)(param_1 + 0x30) = 0xff;
    *(undefined1 *)(param_1 + 0x33) = 0xff;
    *(undefined4 *)(param_1 + 0x70) = 0xffffffff;
    *(undefined4 *)(param_1 + 0x74) = 0xffffffff;
  }
  return;
}

