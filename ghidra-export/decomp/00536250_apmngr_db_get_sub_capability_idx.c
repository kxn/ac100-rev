// func apmngr_db_get_sub_capability_idx @ 00536250 size=48

undefined4 apmngr_db_get_sub_capability_idx(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if (((param_1 != 0x2c) && (uVar1 = 2, param_1 != 0x5f)) && (uVar1 = 0xffffffff, param_1 == 2)) {
    uVar1 = 1;
  }
  return uVar1;
}

