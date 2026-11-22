// func cloud_mngt_global_config_show @ 0049c2c0 size=1

void cloud_mngt_global_config_show(void)

{
  puts("=====cloud mngt global config=====");
  printf("device mac :   %s\n",device_mac);
  printf("device name :   %s\n",&g_device_name);
  printf("device type :  %s\n",&device_type);
  printf("site id :      %s\n",site_id);
  printf("firmware id :  %s\n",&firmware_id);
  printf("ap_report_switch : %d\n",ap_report_switch);
  printf("ap_report_interval :%d\n",ap_report_interval);
  printf("ap_report_count :%d\n",ap_report_count);
  printf("client_report_switch : %d\n",client_report_switch);
  printf("client_report_interval :%d\n",client_report_interval);
  printf("client_report_count :%d\n",client_report_count);
  printf("cloud_config_switch :%d\n",cloud_config_switch);
  printf("cloud_mngt_send_pkt_switch :%d\n",(int)cloud_mngt_send_pkt_switch);
  (*(code *)PTR_puts_00758f90)("================================");
  return;
}

