// func _wsta_db_tmp_hash_show_cb @ 00636990 size=92

void _wsta_db_tmp_hash_show_cb(int param_1)

{
  printf(" mac: %02x:%02x:%02x:%02x:%02x:%02x\n",(uint)*(byte *)(param_1 + 0x68),
         (uint)*(byte *)(param_1 + 0x69),(uint)*(byte *)(param_1 + 0x6a),
         (uint)*(byte *)(param_1 + 0x6b),(uint)*(byte *)(param_1 + 0x6c),
         (uint)*(byte *)(param_1 + 0x6d));
  printf("sta leave time:%d.\n",*(undefined4 *)(param_1 + 0x30));
  return;
}

