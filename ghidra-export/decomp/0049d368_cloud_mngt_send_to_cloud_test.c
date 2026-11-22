// func cloud_mngt_send_to_cloud_test @ 0049d368 size=1

void cloud_mngt_send_to_cloud_test(int param_1)

{
  int iVar1;
  undefined4 uStack_48;
  char acStack_44 [44];
  
  uStack_48 = 0;
  memset(acStack_44,0,0x28);
  for (iVar1 = 0; iVar1 < param_1; iVar1 = iVar1 + 1) {
    sprintf(acStack_44,"c_test_thread%d",iVar1);
    FUN_004084e0(&uStack_48,acStack_44,cloud_mngt_send_to_cloud_thread_callback,0);
  }
  return;
}

