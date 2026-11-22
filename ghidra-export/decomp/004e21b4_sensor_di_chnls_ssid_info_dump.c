// func sensor_di_chnls_ssid_info_dump @ 004e21b4 size=276

void sensor_di_chnls_ssid_info_dump(uint param_1)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar2 = _sensor_di_db_get_sensor_node_from_cached_list(param_1 & 0xffff);
  if (iVar2 == 0) {
    printf("sensor_id=%d\'s data not found\n",param_1 & 0xffff);
    return;
  }
  for (iVar2 = FUN_004081b0(iVar2 + 0x18); iVar2 != 0; iVar2 = FUN_00408680(iVar2)) {
    puts("========");
    if (*(char *)(iVar2 + 0x49) == '\0') {
      printf("ssid_name=%s\n",iVar2 + 0x18);
      cVar1 = *(char *)(iVar2 + 0x49);
    }
    else {
      puts("///////////////////////////");
      cVar1 = *(char *)(iVar2 + 0x49);
    }
    printf("ssid_null=%d\n",(int)cVar1);
    uVar3 = FUN_00407fe0(iVar2 + 0xc);
    printf("bssid_num=%d\n",uVar3);
  }
  return;
}

