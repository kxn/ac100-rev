// func serv_msg_destroy @ 005998ec size=128

void serv_msg_destroy(int param_1)

{
  int iVar1;
  
  if (param_1 == 0) {
    printf("[ASSERT]%32s():%4d assert(%s) failed\n","serv_msg_destroy",0x94,"(NULL != msg_mngr)");
    return;
  }
  while (iVar1 = FUN_004081b0(param_1 + 4), iVar1 != 0) {
    FUN_00408500(iVar1);
    FUN_00407df0(iVar1);
  }
  return;
}

