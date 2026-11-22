// func uac_com_get_dev_sales_method @ 00516d58 size=476

/* WARNING: Heritage AFTER dead removal. Example location: r0x00781a90 : 0x00516e54 */
/* WARNING: Restarted to delay deadcode elimination for space: ram */

undefined4 uac_com_get_dev_sales_method(char *param_1,uint param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 auStack_48 [32];
  int local_28;
  
  uVar2 = 0xffffffff;
  if ((param_1 != (char *)0x0) && (1 < param_2)) {
    if (DAT_00781a94 == 0) {
      if (uac_comm_dbg_switch != 0) {
        printf("[UAC_COMM_DBG]%s()/line %d : Start to init value first time.\n",
               "uac_com_get_dev_sales_method",0xf0);
      }
      memcpy(auStack_48,PTR_DAT_007591ac + 0x1ea8,0x24);
      iVar1 = uac_com_uci_parse_req("device_info","info",auStack_48,1);
      if (iVar1 != 0) {
        if (uac_comm_err_switch == 0) {
          return 0xffffffff;
        }
        printf("[UAC_COMM_ERR]%s()/line %d : uci req parse failed.\n","uac_com_get_dev_sales_method"
               ,0xf9);
        return 0xffffffff;
      }
      if (local_28 == 0) {
        if (uac_comm_dbg_switch != 0) {
          printf("[UAC_COMM_DBG]%s()/line %d : Read fields \'%s.%s.%s\' failed, use default sales method \'%s\'.\n"
                 ,"uac_com_get_dev_sales_method",0xfe,"device_info","info","sales_method","channel")
          ;
        }
        strncpy(&dev_sales_method,"channel",0x80);
      }
      DAT_00781a94 = 1;
    }
    uVar2 = 0;
    strncpy(param_1,&dev_sales_method,param_2 - 1);
    param_1[param_2 - 1] = '\0';
  }
  return uVar2;
}

