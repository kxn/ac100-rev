// func sensor_test_db_get_stage_type_str_from_enum @ 00507768 size=308

undefined4 sensor_test_db_get_stage_type_str_from_enum(undefined4 param_1,char *param_2)

{
  char *__src;
  undefined4 uVar1;
  
  if (param_2 == (char *)0x0) {
    uVar1 = 0xffffffff;
    if (sensor_test_err_switch != '\0') {
      printf("[SENSOR_TEST_ERROR]%s()/%d stage_type_str is NULL\n",
             "sensor_test_db_get_stage_type_str_from_enum",0x1773);
    }
  }
  else {
    switch(param_1) {
    case 1:
      __src = "dns";
      break;
    case 2:
      __src = "arp";
      break;
    case 3:
      __src = "icmp";
      break;
    case 4:
      __src = "radius";
      break;
    case 5:
      __src = "tcp";
      break;
    case 6:
      __src = "http";
      break;
    case 7:
      __src = "ftp";
      break;
    case 8:
      __src = "scan";
      break;
    case 9:
      __src = "auth";
      break;
    case 10:
      __src = "assoc";
      break;
    case 0xb:
      __src = "encryption";
      break;
    case 0xc:
      __src = "dhcp";
      break;
    case 0xd:
      __src = "speed";
      break;
    default:
      __src = "--";
    }
    uVar1 = 0;
    strncpy(param_2,__src,0x10);
  }
  return uVar1;
}

