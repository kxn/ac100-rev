// func wportal_stream_statistics_cb @ 0040d0dc size=172

undefined4 wportal_stream_statistics_cb(int param_1)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  undefined1 auStack_190 [368];
  int local_20;
  uint local_1c;
  int local_18;
  uint local_14;
  
  memset(auStack_190,0,0x180);
  FUN_004082d0(wportal_sta_update_mutex,0xffffffff);
  iVar1 = wportal_db_aut_get(param_1,auStack_190);
  if (iVar1 == 0) {
    uVar2 = local_1c + *(int *)(param_1 + 0x20);
    local_20 = (uint)(uVar2 < local_1c) + local_20;
    uVar3 = local_14 + *(int *)(param_1 + 0x24);
    local_18 = (uint)(uVar3 < local_14) + local_18;
    local_1c = uVar2;
    local_14 = uVar3;
    wportal_db_aut_set(auStack_190);
  }
  FUN_00407f30(wportal_sta_update_mutex);
  return 0;
}

