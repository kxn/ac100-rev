// func uac_cfg_trigger_changed_by_restore @ 0051329c size=28

void uac_cfg_trigger_changed_by_restore(void)

{
  system("ubus call cloudclient notify_cloud_cfg_to_sync -t 5 >/dev/null");
  return;
}

