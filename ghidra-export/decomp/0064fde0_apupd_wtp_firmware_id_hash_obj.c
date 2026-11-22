// func apupd_wtp_firmware_id_hash_obj @ 0064fde0 size=112

undefined4 apupd_wtp_firmware_id_hash_obj(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  if (param_1 == 0) {
    if ((g_apupd_error != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
      printf("[APUPD_ERROR]%32s() %05d: inputs error.\r\n","apupd_wtp_firmware_id_hash_obj",0x317);
    }
    return 0;
  }
  uVar1 = FUN_004083d0(param_1 + 0x18,0x10,0);
  return uVar1;
}

