// func _apdb_extend_str_transfer_to_cap @ 005fc5c0 size=436

undefined4 _apdb_extend_str_transfer_to_cap(int param_1,uint param_2,void *param_3,size_t param_4)

{
  char cVar1;
  size_t sVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  undefined4 uVar7;
  
  if ((((param_1 == 0) || ((int)param_2 < 1)) || (param_3 == (void *)0x0)) || ((int)param_4 < 1)) {
    uVar7 = 0xffffffff;
    if (apdb_err_switch != 0) {
      printf("[APDB_ERROR]%s()/line %d : Input error.\n","_apdb_extend_str_transfer_to_cap",0x115);
    }
  }
  else {
    memset(param_3,0,param_4);
    sVar2 = ((int)param_2 >> 1) + 1;
    if ((param_2 & 1) == 0) {
      sVar2 = (int)param_2 >> 1;
    }
    iVar4 = param_1 + param_2;
    if ((int)param_4 < (int)sVar2) {
      sVar2 = param_4;
    }
    iVar6 = (int)param_3 + param_4;
    iVar3 = 0;
    while (iVar3 < (int)sVar2) {
      uVar5 = *(byte *)(iVar4 + -1) - 0x30 & 0xff;
      if ((0x36 < uVar5) || (cVar1 = (&DAT_00701c38)[uVar5], cVar1 == -1)) {
        if (apdb_err_switch == 0) {
          return 0xffffffff;
        }
        uVar7 = 0x120;
LAB_005fc690:
        printf("[APDB_ERROR]%s()/line %d : Illegal cap str %s.\n","_apdb_extend_str_transfer_to_cap"
               ,uVar7,param_1);
        return 0xffffffff;
      }
      iVar3 = iVar3 + 1;
      *(char *)(iVar6 + -1) = cVar1;
      if (iVar3 * 2 <= (int)param_2) {
        uVar5 = *(byte *)(iVar4 + -2) - 0x30 & 0xff;
        if ((0x36 < uVar5) || ((&DAT_00701c38)[uVar5] == -1)) {
          if (apdb_err_switch == 0) {
            return 0xffffffff;
          }
          uVar7 = 0x129;
          goto LAB_005fc690;
        }
        *(char *)(iVar6 + -1) = cVar1 + (&DAT_00701c38)[uVar5] * '\x10';
      }
      iVar6 = iVar6 + -1;
      iVar4 = iVar4 + -2;
    }
    uVar7 = 0;
  }
  return uVar7;
}

