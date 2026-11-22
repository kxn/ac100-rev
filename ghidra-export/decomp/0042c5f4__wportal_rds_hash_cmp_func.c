// func _wportal_rds_hash_cmp_func @ 0042c5f4 size=160

uint _wportal_rds_hash_cmp_func(int param_1,char *param_2)

{
  uint uVar1;
  int iVar2;
  char local_44 [28];
  char local_28 [24];
  
  memcpy(local_28,param_2,0x14);
  uVar1 = 0;
  if (*(char *)(param_1 + 0x120) == *param_2) {
    local_28[0] = *(char *)(param_1 + 0x120);
    for (; uVar1 < 0x14; uVar1 = uVar1 + 1) {
      local_44[uVar1] = local_28[uVar1];
    }
    iVar2 = FUN_004085c0(*(undefined4 *)(param_1 + 0x120),*(undefined4 *)(param_1 + 0x124),
                         *(undefined4 *)(param_1 + 0x128),*(undefined4 *)(param_1 + 300),
                         *(undefined4 *)(param_1 + 0x130));
    uVar1 = (uint)(iVar2 != 0);
  }
  return uVar1;
}

