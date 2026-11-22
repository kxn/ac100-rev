// func cloud_mngt_packet_send_test @ 0049d408 size=132

void cloud_mngt_packet_send_test(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = FUN_00408450(param_1,0x2151);
  iVar2 = 0;
  if (iVar1 == 0) {
    return;
  }
  for (; iVar2 < param_1; iVar2 = iVar2 + 1) {
    *(undefined1 *)(iVar1 + iVar2) = 0x31;
  }
  *(undefined1 *)(iVar1 + param_1 + -1) = 0;
  cloud_mngt_send_to_cloud(3,iVar1);
  FUN_00407df0(iVar1);
  return;
}

