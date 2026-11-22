// func sensor_mngt_destroy @ 004ea55c size=1

void sensor_mngt_destroy(int param_1)

{
  int iVar1;
  
  if (param_1 == 0) {
    printf("[ASSERT]%32s():%4d assert(%s) failed\n","sensor_mngt_destroy",0x74,"(NULL != msg_mngr)")
    ;
    return;
  }
  while (iVar1 = FUN_004081b0(param_1 + 0x38), iVar1 != 0) {
    FUN_00408500(iVar1);
    FUN_00407df0(iVar1);
  }
  return;
}

