// func apupd_image_hard_ver_get_test @ 00649acc size=1

void apupd_image_hard_ver_get_test(void)

{
  ushort *puVar1;
  ushort uVar2;
  int iVar3;
  uint uVar4;
  ushort *puVar5;
  uint uStack_6c0;
  undefined1 auStack_6bc [66];
  ushort auStack_67a [317];
  undefined1 auStack_400 [1000];
  
  memset(&uStack_6c0,0,0x2c0);
  memset(auStack_400,0,1000);
  apupd_image_file_read("/tmp/supp",auStack_400,1000);
  iVar3 = apupd_image_hard_ver_get_from_str(auStack_400,&uStack_6c0);
  if (iVar3 == 0) {
    puVar5 = auStack_67a;
    for (uVar4 = 0; uVar4 < uStack_6c0; uVar4 = uVar4 + 1) {
      uVar2 = *puVar5;
      puVar1 = puVar5 + 1;
      puVar5 = puVar5 + 0x23;
      printf("model name: %s, hwver:%d.%d\n",auStack_6bc + uVar4 * 0x46,(uint)uVar2,(uint)*puVar1);
    }
  }
  else if ((g_apupd_error != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
    printf("[APUPD_ERROR]%32s() %05d: apupd_image_hard_ver_get_from_str failed.\r\n",
           "apupd_image_hard_ver_get_test",0x1362);
  }
  return;
}

