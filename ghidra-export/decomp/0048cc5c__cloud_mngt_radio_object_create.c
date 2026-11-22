// func _cloud_mngt_radio_object_create @ 0048cc5c size=1008

int _cloud_mngt_radio_object_create(int param_1)

{
  short sVar1;
  int iVar2;
  undefined4 uVar3;
  char cVar4;
  int iVar5;
  
  iVar2 = json_object_new_object();
  if (iVar2 == 0) {
    if (cloud_mngt_err_switch != '\0') {
      printf("[CLOUD_MNGT_ERROR]%s()/%d Failed create json_freq_obj.\n",
             "_cloud_mngt_radio_object_create",0x3c2);
    }
  }
  else {
    uVar3 = json_object_new_int((int)*(short *)(param_1 + 0x1c));
    json_object_object_add(iVar2,"max_ssid",uVar3);
    uVar3 = json_object_new_int((int)*(short *)(param_1 + 0x1e));
    json_object_object_add(iVar2,"max_stations",uVar3);
    if (*(short *)(param_1 + 0x20) == 0) {
      sVar1 = *(short *)(param_1 + 0x22);
    }
    else {
      uVar3 = json_object_new_int();
      json_object_object_add(iVar2,"max_tx_power",uVar3);
      sVar1 = *(short *)(param_1 + 0x22);
    }
    if (sVar1 == 0) {
      sVar1 = *(short *)(param_1 + 0x24);
    }
    else {
      uVar3 = json_object_new_int();
      json_object_object_add(iVar2,"min_tx_power",uVar3);
      sVar1 = *(short *)(param_1 + 0x24);
    }
    if (sVar1 == 0) {
      sVar1 = *(short *)(param_1 + 0x26);
    }
    else {
      uVar3 = json_object_new_int();
      json_object_object_add(iVar2,"dft_tx_power",uVar3);
      sVar1 = *(short *)(param_1 + 0x26);
    }
    if (sVar1 == 0) {
      sVar1 = *(short *)(param_1 + 0x28);
    }
    else {
      uVar3 = json_object_new_int();
      json_object_object_add(iVar2,"real_max_tx_power",uVar3);
      sVar1 = *(short *)(param_1 + 0x28);
    }
    if (sVar1 == 0) {
      sVar1 = *(short *)(param_1 + 0x2a);
    }
    else {
      uVar3 = json_object_new_int();
      json_object_object_add(iVar2,"real_min_tx_power",uVar3);
      sVar1 = *(short *)(param_1 + 0x2a);
    }
    if (sVar1 == 0) {
      iVar5 = *(int *)(param_1 + 0x30);
    }
    else {
      uVar3 = json_object_new_int();
      json_object_object_add(iVar2,"real_dft_tx_power",uVar3);
      iVar5 = *(int *)(param_1 + 0x30);
    }
    if (iVar5 == -1) {
      cVar4 = *(char *)(param_1 + 0x38);
    }
    else {
      uVar3 = json_object_new_int();
      json_object_object_add(iVar2,"dft_bw_mode",uVar3);
      cVar4 = *(char *)(param_1 + 0x38);
    }
    if (cVar4 == '\0') {
      iVar5 = *(int *)(param_1 + 4);
    }
    else {
      uVar3 = json_object_new_string(param_1 + 0x38);
      json_object_object_add(iVar2,"mutex_channel",uVar3);
      iVar5 = *(int *)(param_1 + 4);
    }
    if (iVar5 == 1) {
      uVar3 = json_object_new_boolean(1);
      json_object_object_add(iVar2,"support_11ac",uVar3);
      iVar5 = *(int *)(param_1 + 8);
    }
    else {
      iVar5 = *(int *)(param_1 + 8);
    }
    if (iVar5 == 1) {
      uVar3 = json_object_new_boolean(1);
      json_object_object_add(iVar2,"support_11ax",uVar3);
      iVar5 = *(int *)(param_1 + 0xc);
    }
    else {
      iVar5 = *(int *)(param_1 + 0xc);
    }
    if (iVar5 == 1) {
      uVar3 = json_object_new_boolean(1);
      json_object_object_add(iVar2,"support_160M",uVar3);
      iVar5 = *(int *)(param_1 + 0x10);
    }
    else {
      iVar5 = *(int *)(param_1 + 0x10);
    }
    if (iVar5 == 1) {
      uVar3 = json_object_new_boolean(1);
      json_object_object_add(iVar2,"support_80M_80M",uVar3);
      iVar5 = *(int *)(param_1 + 0x14);
    }
    else {
      iVar5 = *(int *)(param_1 + 0x14);
    }
    if (iVar5 == 1) {
      uVar3 = json_object_new_boolean(1);
      json_object_object_add(iVar2,"support_11be",uVar3);
      iVar5 = *(int *)(param_1 + 0x18);
    }
    else {
      iVar5 = *(int *)(param_1 + 0x18);
    }
    if (iVar5 == 1) {
      uVar3 = json_object_new_boolean(1);
      json_object_object_add(iVar2,"support_240m",uVar3);
      iVar5 = *(int *)(param_1 + 0x34);
    }
    else {
      iVar5 = *(int *)(param_1 + 0x34);
    }
    if (iVar5 == 1) {
      uVar3 = json_object_new_boolean(1);
      json_object_object_add(iVar2,"support_WPA3",uVar3);
      iVar5 = *(int *)(param_1 + 0x110);
    }
    else {
      iVar5 = *(int *)(param_1 + 0x110);
    }
    if (iVar5 != 0) {
      iVar5 = _cloud_mngt_radio_object_create();
      if (iVar5 == 0) {
        if (cloud_mngt_err_switch != '\0') {
          printf("[CLOUD_MNGT_ERROR]%s()/%d Failed create json_freq_multi_obj.\n",
                 "_cloud_mngt_radio_object_create",0x41e);
        }
        json_object_put(iVar2);
        iVar2 = 0;
      }
      else {
        json_object_object_add(iVar2,"opposite_radio",iVar5);
      }
    }
  }
  return iVar2;
}

