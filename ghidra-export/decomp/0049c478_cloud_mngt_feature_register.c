// func cloud_mngt_feature_register @ 0049c478 size=52

void cloud_mngt_feature_register(void)

{
  if (cloud_mngt_apdb_report_switch != '\0') {
    system(
          "ubus call cloudclient register_cmd_callback \'{\"register_notify_cmd\":\"echo 11\",\"wait_time\":0,\"type\":\"feature\",\"action\":\"add\"}\' &> /dev/null"
          );
  }
  system(
        "ubus call cloudclient register_cmd_callback \'{\"register_notify_cmd\":\"echo 17\",\"wait_time\":0,\"type\":\"feature\",\"action\":\"add\"}\' &> /dev/null"
        );
  return;
}

