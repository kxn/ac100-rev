// func apdb_support_80M_80M_by_id @ 0060a9c4 size=1

uint apdb_support_80M_80M_by_id(undefined4 param_1,int param_2,uint param_3,uint param_4)

{
  int iVar1;
  char *__format;
  undefined4 uVar2;
  uint uVar3;
  uint *puVar4;
  int aiStack_20 [3];
  
  aiStack_20[0] = 0;
  if (param_2 == 0) {
    if (apdb_err_switch != 0) {
      __format = "[APDB_ERROR]%s()/line %d : the fwid is NULL\n";
      uVar2 = 0x2961;
      goto code_r0x0060aaa0;
    }
  }
  else {
    iVar1 = apdb_get_model_by_id(param_1,param_2,aiStack_20);
    if (iVar1 == 0) {
      uVar3 = (param_3 & 0xff) - 1 & 0xff;
      FUN_004082d0(l_apdb_mutex,0xffffffff);
      if ((*(int *)(aiStack_20[0] + 0x10) - 1U & 0xff) < uVar3) {
        uVar3 = 0;
        if (apdb_warning_switch != 0) {
          printf("[APDB_WARNING]%s()/line %d : input radio id[%d] out of range[1,%d].\n",
                 "apdb_support_80M_80M_by_id",0x296f,param_3 & 0xff,*(int *)(aiStack_20[0] + 0x10));
        }
      }
      else {
        iVar1 = uVar3 * 0x114;
        if (param_4 < 2) {
          puVar4 = (uint *)(*(int *)(aiStack_20[0] + 0x28) + iVar1);
          if (*puVar4 == param_4) {
            uVar3 = puVar4[4];
          }
          else {
            puVar4 = (uint *)puVar4[0x44];
            if ((puVar4 == (uint *)0x0) || (*puVar4 != param_4)) {
              FUN_00407f30(l_apdb_mutex);
              if (apdb_warning_switch == 0) {
                return 0;
              }
              printf("[APDB_WARNING]%s()/line %d : Illegal freq %s.\n","apdb_support_80M_80M_by_id",
                     0x297f,(&PTR_s_2_4GHz_00702480)[param_4]);
              return 0;
            }
            uVar3 = puVar4[4];
          }
        }
        else {
          uVar3 = *(uint *)(*(int *)(aiStack_20[0] + 0x28) + iVar1 + 0x10);
        }
      }
      FUN_00407f30(l_apdb_mutex);
      return uVar3;
    }
    if (apdb_warning_switch != 0) {
      __format = "[APDB_WARNING]%s()/line %d : get model failed\n";
      uVar2 = 0x2967;
code_r0x0060aaa0:
      printf(__format,"apdb_support_80M_80M_by_id",uVar2);
      return 0;
    }
  }
  return 0;
}

