// func capwap_ac_session_hash_cmp @ 0058f8f0 size=224

bool capwap_ac_session_hash_cmp(int param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  char *pcVar4;
  undefined1 local_2c [32];
  
  if (param_1 == 0) {
    uVar3 = 0x7b;
    pcVar4 = "session";
  }
  else {
    if (param_2 != 0) {
      for (uVar1 = 0; uVar1 < 0x14; uVar1 = uVar1 + 1) {
        local_2c[uVar1] = *(undefined1 *)(param_2 + uVar1);
      }
      iVar2 = FUN_004085c0(*(undefined4 *)(param_1 + 0x2c),*(undefined4 *)(param_1 + 0x30),
                           *(undefined4 *)(param_1 + 0x34),*(undefined4 *)(param_1 + 0x38),
                           *(undefined4 *)(param_1 + 0x3c));
      if (iVar2 == 0) {
        return false;
      }
      return *(short *)(param_1 + 0x40) == *(short *)(param_2 + 0x14);
    }
    uVar3 = 0x7c;
    pcVar4 = "key";
  }
  printf("[ASSERT]%32s():%4d assert(%s) failed\n","capwap_ac_session_hash_cmp",uVar3,pcVar4);
  return false;
}

