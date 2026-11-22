// func cloud_mngt_msg_report_test @ 0049d48c size=1

void cloud_mngt_msg_report_test(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  
  switch(param_1) {
  case 3:
    cloud_mngt_ap_add_report(1);
    return;
  case 4:
    cloud_mngt_ap_add_report(0);
    return;
  case 5:
    cloud_mngt_client_first_report();
    return;
  case 6:
    if (ap_report_switch != 0) {
      FUN_0049743c();
      return;
    }
    break;
  case 7:
    if (ap_report_switch != 0) {
      FUN_0049af28();
      return;
    }
    break;
  case 8:
    cloud_mngt_client_update_report();
    return;
  default:
    if (cloud_mngt_err_switch != '\0') {
      printf("[CLOUD_MNGT_ERROR]%s()/%d Unknown msg op[%d]\n","cloud_mngt_msg_report_test",0x2182);
      return;
    }
    break;
  case 0xc:
    nms_client_update_report(1);
    return;
  case 0x11:
    uVar1 = 1;
    goto LAB_0049d52c;
  case 0x12:
    uVar1 = 2;
    goto LAB_0049d52c;
  case 0x13:
    uVar1 = 3;
LAB_0049d52c:
    nms_report_ap_stats_update_report(uVar1,1,param_3,param_1);
    return;
  }
  return;
}

