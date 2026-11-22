// func serv_ent_handle @ 00598998 size=188

undefined4 serv_ent_handle(undefined2 param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  
  if (param_2 == 0) {
    printf("[ASSERT]%32s():%4d assert(%s) failed\n","serv_ent_handle",0x14a,"NULL != basic");
    uVar2 = 0xffffffff;
  }
  else {
    iVar1 = serv_ent_mngr_get(param_1);
    uVar2 = 0xffffffff;
    if (iVar1 != 0) {
      for (iVar1 = FUN_004081b0(iVar1 + 4); iVar1 != 0; iVar1 = FUN_00408680(iVar1)) {
        if (*(code **)(iVar1 + 0x10) != (code *)0x0) {
          (**(code **)(iVar1 + 0x10))(param_2,param_3,param_4);
        }
      }
      uVar2 = 0;
    }
  }
  return uVar2;
}

