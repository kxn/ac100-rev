// func _fw_id_hash_show_cb @ 005f99d8 size=108

void _fw_id_hash_show_cb(int param_1)

{
  undefined1 auStack_88 [128];
  
  memset(auStack_88,0,0x80);
  if (param_1 == 0) {
    puts("Get fw_id hash node failed");
  }
  FUN_004084f0(param_1,0x10,auStack_88);
  printf("fw_id:%s, apdb_index:%d\n",auStack_88,*(undefined4 *)(param_1 + 0x10));
  return;
}

