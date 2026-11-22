// func apupd_get_cloud_image_info_from_firmware_info @ 00409664 size=224

undefined4 apupd_get_cloud_image_info_from_firmware_info(void *param_1,uint *param_2)

{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  
  uVar1 = 0xffffffff;
  if ((param_1 != (void *)0x0) && (param_2 != (uint *)0x0)) {
    memcpy(param_2 + 1,param_1,0x10);
    *param_2 = (uint)*(ushort *)((int)param_1 + 0x10);
    uVar2 = (uint)*(ushort *)((int)param_1 + 0x4a);
    if (0x60 < uVar2) {
      if ((g_apupd_debug != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
        printf("[APUPD_DEBUG]%32s() %05d: Fl list num:%d is out of range:%d .\r\n",
               "apupd_get_cloud_image_info_from_firmware_info",0x5bd,
               (uint)*(ushort *)((int)param_1 + 0x4a),0x60);
      }
      uVar2 = 0x60;
    }
    param_2[0x185] = uVar2;
    memset(param_2 + 5,0,0x600);
    memcpy(param_2 + 5,(void *)((int)param_1 + 0x8c),param_2[0x185] << 4);
    uVar1 = 0;
  }
  return uVar1;
}

