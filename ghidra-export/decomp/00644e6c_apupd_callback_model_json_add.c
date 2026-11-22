// func apupd_callback_model_json_add @ 00644e6c size=768

undefined4 apupd_callback_model_json_add(int param_1,uint *param_2)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  char *pcVar5;
  undefined4 uVar6;
  uint uVar7;
  undefined4 uVar8;
  
  if ((g_apupd_debug != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
    printf("[APUPD_DEBUG]%32s() %05d: apupd_callback_model_json_add start\r\n",
           "apupd_callback_model_json_add",0x24f);
  }
  if (((param_1 == 0) || (param_2 == (uint *)0x0)) || (param_2[7] == 0)) {
    uVar8 = 0xffffffff;
    if (g_apupd_error == 0) {
      return 0xffffffff;
    }
    iVar2 = is_target_debug_ap();
    if (iVar2 == 0) {
      return 0xffffffff;
    }
    pcVar5 = "[APUPD_ERROR]%32s() %05d: inputs error.\r\n";
    uVar6 = 0x254;
  }
  else {
    if (1 < *(int *)(param_1 + 0x7ec) - 1U) {
      uVar8 = 0;
      if (g_apupd_debug == 0) {
        return 0;
      }
      iVar2 = is_target_debug_ap();
      if (iVar2 == 0) {
        return 0;
      }
      pcVar5 = "[APUPD_DEBUG]%32s() %05d: model don\'t need multi-upgrade.\r\n";
      uVar6 = 0x259;
      goto LAB_00644f54;
    }
    if (param_2[5] == 0xffffffff) {
      cVar1 = *(char *)(param_2 + 6);
    }
    else {
      if (param_2[5] != *(uint *)(param_1 + 0x134)) {
        if (g_apupd_debug == 0) {
          return 0;
        }
        iVar2 = is_target_debug_ap();
        if (iVar2 == 0) {
          return 0;
        }
        uVar3 = *(uint *)(param_1 + 0x134);
        uVar7 = param_2[5];
        pcVar5 = "[APUPD_DEBUG]%32s() %05d: is_mesh_device not match(%d-%d).\r\n";
        uVar8 = 0x25e;
        goto LAB_00645038;
      }
      cVar1 = *(char *)(param_2 + 6);
    }
    if (((int)cVar1 >> (*(byte *)(param_1 + 0x138) & 0x1f) & 1U) == 0) {
      if (g_apupd_debug == 0) {
        return 0;
      }
      iVar2 = is_target_debug_ap();
      if (iVar2 == 0) {
        return 0;
      }
      uVar3 = (uint)*(byte *)(param_1 + 0x138);
      uVar7 = (uint)*(char *)(param_2 + 6);
      pcVar5 = "[APUPD_DEBUG]%32s() %05d: product_type not match(%d-%d).\r\n";
      uVar8 = 0x263;
LAB_00645038:
      printf(pcVar5,"apupd_callback_model_json_add",uVar8,uVar7,uVar3);
      return 0;
    }
    param_2[4] = param_2[4] + 1;
    uVar8 = 0;
    if (param_2[1] <= param_2[3]) {
      return 0;
    }
    if (param_2[2] < *param_2) {
      param_2[2] = param_2[2] + 1;
      return 0;
    }
    param_2[3] = param_2[3] + 1;
    iVar2 = json_object_new_object();
    if (iVar2 == 0) {
      uVar8 = 0xffffffff;
      if (g_apupd_error == 0) {
        return 0xffffffff;
      }
      iVar2 = is_target_debug_ap();
      if (iVar2 == 0) {
        return 0xffffffff;
      }
      pcVar5 = "[APUPD_ERROR]%32s() %05d: malloc json obj failed.\r\n";
      uVar6 = 0x275;
    }
    else {
      iVar4 = apupd_model_from_struct_to_json(param_1,iVar2);
      if (iVar4 == -1) {
        if ((g_apupd_error != 0) && (iVar4 = is_target_debug_ap(), iVar4 != 0)) {
          printf("[APUPD_ERROR]%32s() %05d: turn model to json failed.\r\n",
                 "apupd_callback_model_json_add",0x27c);
        }
        json_object_put(iVar2);
        return 0xffffffff;
      }
      json_object_array_add(param_2[7],iVar2);
      if (g_apupd_debug == 0) {
        return 0;
      }
      iVar2 = is_target_debug_ap();
      if (iVar2 == 0) {
        return 0;
      }
      pcVar5 = "[APUPD_DEBUG]%32s() %05d: apupd_callback_model_json_add end\r\n";
      uVar6 = 0x282;
    }
  }
LAB_00644f54:
  printf(pcVar5,"apupd_callback_model_json_add",uVar6);
  return uVar8;
}

