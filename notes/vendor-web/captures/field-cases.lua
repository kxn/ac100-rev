return {
  {name="ac_alias_changed", op=2, data={}},
  {name="ac_audit", op=2, data={
    enable = 0,
    remote_ip = "192.168.1.1"
  }},
  {name="ac_autorrm_list", op=2, data={
    id = 0
  }},
  {name="ac_balance", op=0, data={
    ap_ids = {},
    dif_threshold = "probe",
    enable = 0,
    group_ids = {},
    id = 0,
    index_field = "probe",
    max_fail_num = "probe",
    mode = 0,
    name = "probe",
    rssi_threshold = "probe",
    usr_threshold = "probe"
  }},
  {name="ac_balance", op=1, data={
    id = 0
  }},
  {name="ac_balance", op=2, data={
    ap_ids = {},
    dif_threshold = "probe",
    enable = 0,
    group_ids = {},
    id = 0,
    index_field = "probe",
    max_fail_num = "probe",
    mode = 0,
    name = "probe",
    rssi_threshold = "probe",
    usr_threshold = "probe"
  }},
  {name="ac_balance", op=3, data={
    id = 0,
    index_field = "probe",
    name = "probe",
    size = 10,
    start = 0
  }},
  {name="ac_clear_all_cloud_config_id", op=2, data={}},
  {name="ac_config_id_changed", op=2, data={
    new_config_id = 0
  }},
  {name="ac_datasync_status", op=2, data={
    status = 0
  }},
  {name="ac_forward", op=2, data={
    content = "probe",
    extend_dev_id = 0,
    requests = {}
  }},
  {name="ac_forward", op=3, data={
    device_type = "probe",
    extend_dev_ids = {},
    request_id = {999}
  }},
  {name="ac_manualrrm", op=2, data={
    ap_ids = {},
    autorrm_enable = 0,
    autorrm_timeobj = "2026-01-01 00:00:00",
    bw_2g = "probe",
    bw_5g = "probe",
    chnl_2g_set = "probe",
    chnl_5g1_set = "probe",
    chnl_enable = 0,
    freq_enable = 0,
    group_ids = {},
    id = 0,
    index_field = "probe",
    max_pwr_2g = "probe",
    max_pwr_5g = "probe",
    min_pwr_2g = "probe",
    min_pwr_5g = "probe",
    name = "probe",
    pwr_enable = 0,
    pwr_threshold_2g = "probe",
    pwr_threshold_5g = "probe",
    setting_id = 0
  }},
  {name="ac_mesh_discover_cap_change", op=2, data={
    cap_id = 0,
    mac = "00:11:22:33:44:55"
  }},
  {name="ac_mesh_discover_list", op=3, data={
    size = 10,
    start = 0
  }},
  {name="ac_mesh_discover_status", op=3, data={}},
  {name="ac_mesh_global_settings", op=2, data={
    backhaul_key = "probe",
    backhaul_ssid = "probe",
    backhaul_token = "probe",
    bh_work_mode = "probe",
    enable = 0,
    re_auto_switch = 0,
    re_recover_flag = "probe",
    web_password = "12345678"
  }},
  {name="ac_mesh_stop_discover", op=2, data={}},
  {name="ac_mesh_topology", op=3, data={}},
  {name="ac_mesh_trigger_discover", op=2, data={}},
  {name="ac_mesh_trigger_pair", op=2, data={
    cap_id = 0,
    dev_info = {},
    mac = "00:11:22:33:44:55"
  }},
  {name="ac_mesh_trigger_pair_all", op=2, data={}},
  {name="ac_mesh_wan_status", op=2, data={
    wan_status = "probe"
  }},
  {name="ac_notify_master_sync_data", op=2, data={}},
  {name="ac_passthrough", op=2, data={
    ap_mac = "00:11:22:33:44:55",
    apmng_passthrough = "probe",
    filepath = "probe",
    get_rsponse_info_sync = "probe",
    need_result = "probe",
    params = {},
    passthrough_to_subdevice = "probe",
    requestData = {},
    request_id = 0,
    request_info = {}
  }},
  {name="ac_passthrough", op=3, data={
    ap_mac = "00:11:22:33:44:55",
    filepath = "probe",
    get_rsponse_info_sync = "probe",
    need_result = "probe",
    request_id = 0,
    request_info = {}
  }},
  {name="ac_rate", op=2, data={
    ["11a_base"] = "probe",
    ["11a_mult"] = "probe",
    ["11a_supp"] = "probe",
    ["11ac_base"] = "probe",
    ["11ac_supp"] = "probe",
    ["11ax_base"] = "probe",
    ["11ax_supp"] = "probe",
    ["11b_base"] = "probe",
    ["11b_mult"] = "probe",
    ["11b_supp"] = "probe",
    ["11g_base"] = "probe",
    ["11g_mult"] = "probe",
    ["11g_supp"] = "probe",
    ["11n_base"] = "probe",
    ["11n_supp"] = "probe",
    rate_11a = "probe",
    rate_11ac = "probe",
    rate_11ax = "probe",
    rate_11b = "probe",
    rate_11g = "probe",
    rate_11n = "probe"
  }},
  {name="ac_report", op=2, data={
    active_ap_only = "probe",
    apgroup = "probe",
    content = "probe",
    interval = 0,
    max_load = "probe",
    protocol = 0,
    server_address = "probe",
    server_port = 80,
    state = "probe"
  }},
  {name="ac_roam", op=2, data={
    ap_ids = {},
    blacklist_restrict_time = "2026-01-01 00:00:00",
    group_ids = {},
    id = 0,
    low_rate_kick_2g = "probe",
    low_rate_kick_5g = "probe",
    low_rate_threshold_2g = "probe",
    low_rate_threshold_5g = "probe",
    low_rssi_kick_2g = "probe",
    low_rssi_kick_5g = "probe",
    low_rssi_threshold_2g = "probe",
    low_rssi_threshold_5g = "probe",
    name = "probe",
    rate_trigger_threshold_2g = "probe",
    rate_trigger_threshold_5g = "probe",
    roaming_dif = "probe",
    roaming_threshold_type_2g = "probe",
    roaming_threshold_type_5g = "probe",
    rssi_trigger_threshold_2g = "probe",
    rssi_trigger_threshold_5g = "probe",
    rssi_trigger_threshold_high_performance = "probe",
    stats_interval = "probe",
    stats_switch = 0,
    switch_11k = "probe",
    switch_11r = "probe",
    switch_11v = "probe",
    threshold_check_interval = "probe"
  }},
  {name="ac_roam_list", op=0, data={{
      id = 0,
      name = "probe",
      ap_ids = {},
      group_ids = {},
      switch_11k = 0,
      switch_11v = 0,
      switch_11r = 0,
      roaming_threshold_type_2g = 0,
      rssi_trigger_threshold_2g = 0,
      rssi_trigger_threshold_high_performance = 0,
      low_rssi_kick_2g = 0,
      low_rssi_threshold_2g = 0,
      rate_trigger_threshold_2g = 0,
      low_rate_kick_2g = 0,
      low_rate_threshold_2g = 0,
      roaming_threshold_type_5g = 0,
      rssi_trigger_threshold_5g = 0,
      low_rssi_kick_5g = 0,
      low_rssi_threshold_5g = 0,
      rate_trigger_threshold_5g = 0,
      low_rate_kick_5g = 0,
      low_rate_threshold_5g = 0,
      threshold_check_interval = 0,
      roaming_dif = 0,
      blacklist_restrict_time = 0,
      stats_switch = 0,
      stats_interval = 0
    }}},
  {name="ac_roam_list", op=1, data={
    id = 0
  }},
  {name="ac_roam_list", op=2, data={
    id = 0,
    name = "probe",
    ap_ids = {},
    group_ids = {},
    switch_11k = 0,
    switch_11v = 0,
    switch_11r = 0,
    roaming_threshold_type_2g = 0,
    rssi_trigger_threshold_2g = 0,
    rssi_trigger_threshold_high_performance = 0,
    low_rssi_kick_2g = 0,
    low_rssi_threshold_2g = 0,
    rate_trigger_threshold_2g = 0,
    low_rate_kick_2g = 0,
    low_rate_threshold_2g = 0,
    roaming_threshold_type_5g = 0,
    rssi_trigger_threshold_5g = 0,
    low_rssi_kick_5g = 0,
    low_rssi_threshold_5g = 0,
    rate_trigger_threshold_5g = 0,
    low_rate_kick_5g = 0,
    low_rate_threshold_5g = 0,
    threshold_check_interval = 0,
    roaming_dif = 0,
    blacklist_restrict_time = 0,
    stats_switch = 0,
    stats_interval = 0
  }},
  {name="ac_roam_list", op=3, data={
    ["end"] = "probe",
    id = 0,
    index_field = "probe",
    name = "probe",
    start = 0
  }},
  {name="ac_rrm_list", op=0, data={
    ap_ids = {},
    autorrm_enable = 0,
    autorrm_timeobj = "2026-01-01 00:00:00",
    bw_2g = "probe",
    bw_5g = "probe",
    chnl_2g_set = "probe",
    chnl_5g1_set = "probe",
    chnl_enable = 0,
    freq_enable = 0,
    group_ids = {},
    id = 0,
    index_field = "probe",
    max_pwr_2g = "probe",
    max_pwr_5g = "probe",
    min_pwr_2g = "probe",
    min_pwr_5g = "probe",
    name = "probe",
    pwr_enable = 0,
    pwr_threshold_2g = "probe",
    pwr_threshold_5g = "probe"
  }},
  {name="ac_rrm_list", op=1, data={
    id = 0
  }},
  {name="ac_rrm_list", op=2, data={
    ap_ids = {},
    autorrm_enable = 0,
    autorrm_timeobj = "2026-01-01 00:00:00",
    bw_2g = "probe",
    bw_5g = "probe",
    chnl_2g_set = "probe",
    chnl_5g1_set = "probe",
    chnl_enable = 0,
    freq_enable = 0,
    group_ids = {},
    id = 0,
    index_field = "probe",
    max_pwr_2g = "probe",
    max_pwr_5g = "probe",
    min_pwr_2g = "probe",
    min_pwr_5g = "probe",
    name = "probe",
    pwr_enable = 0,
    pwr_threshold_2g = "probe",
    pwr_threshold_5g = "probe"
  }},
  {name="ac_rrm_list", op=3, data={
    id = 0,
    index_field = "probe",
    name = "probe",
    size = 10,
    start = 0
  }},
  {name="ac_rrm_state", op=3, data={}},
  {name="ac_rrmpara", op=2, data={
    autorrm_date = "2026-01-01 00:00:00",
    autorrm_enable = 0,
    autorrm_time = "2026-01-01 00:00:00",
    bw_2g = "probe",
    bw_5g = "probe",
    chnl_2g_set = "probe",
    chnl_5g1_set = "probe",
    chnl_enable = 0,
    freq_enable = 0,
    group_id_str = 0,
    pwr_enable = 0,
    pwr_max_pwr = "probe",
    pwr_min_pwr = "probe",
    pwr_threshold = "probe"
  }},
  {name="ac_statics", op=2, data={
    clientStats = "probe",
    devStats = "probe",
    radioStats = "probe",
    report_time = 80,
    sample_time = "2026-01-01 00:00:00",
    vapStats = "probe"
  }},
  {name="ap_calibrate", op=2, data={
    file_name = "probe"
  }},
  {name="ap_capture_list", op=0, data={
    ap_id = 0,
    capture_type = "probe",
    channel_str = "probe",
    enable = 0,
    id = 0,
    rf_enable_str = "probe",
    rf_id_str = 0
  }},
  {name="ap_capture_list", op=1, data={
    id = 0
  }},
  {name="ap_capture_list", op=2, data={
    enable = 0,
    id = 0,
    operation = 0
  }},
  {name="ap_capture_list", op=3, data={
    id = 0,
    size = 10,
    start = 0
  }},
  {name="ap_capture_settings", op=2, data={
    enable = 0,
    remote_capture_port = 80
  }},
  {name="ap_count", op=3, data={}},
  {name="ap_count_trend", op=3, data={}},
  {name="ap_crashdump_status_evt", op=2, data={
    entry_id = 0,
    evt = "noop",
    null = "probe"
  }},
  {name="ap_exceed_status", op=3, data={}},
  {name="ap_firmed_model", op=3, data={
    group_id = 0,
    search_name = "probe",
    search_value = "probe",
    size = 10,
    start = 0
  }},
  {name="ap_log_debug_cfg_bind", op=2, data={
    ap_ids = {},
    log_config_id = 0,
    status = 0
  }},
  {name="ap_log_debug_list", op=0, data={
    debug_level = "probe",
    debug_switch = 0,
    log_send_switch = 0,
    model_str = "probe",
    server_ip = "192.168.1.1"
  }},
  {name="ap_log_debug_list", op=3, data={
    ap_id = 0
  }},
  {name="ap_log_display_list", op=3, data={
    ids = {},
    search_name = "probe",
    search_type = "probe",
    search_value = "probe",
    size = 10,
    start = 0
  }},
  {name="ap_log_download_list", op=0, data={
    ap_id = 0,
    log_file_ids = 0
  }},
  {name="ap_log_download_list", op=3, data={}},
  {name="ap_log_download_result", op=2, data={
    ap_id = 0,
    log_file_id = 0,
    result = 0
  }},
  {name="ap_log_download_start", op=2, data={}},
  {name="ap_log_download_status", op=3, data={
    ap_id = 0,
    log_file_fragment = "probe",
    log_file_id = 0,
    log_file_name = "probe"
  }},
  {name="ap_log_export_cb", op=2, data={}},
  {name="ap_log_timer_start", op=2, data={}},
  {name="ap_replace_config", op=2, data={
    file_name = "probe",
    null = "probe"
  }},
  {name="ap_replace_rule", op=2, data={
    source_mac = "00:11:22:33:44:55",
    target_mac = "00:11:22:33:44:55"
  }},
  {name="ap_report_switch", op=2, data={
    site_id = 0,
    status = 0,
    support_new_rule = 80
  }},
  {name="ap_set_token", op=2, data={
    deviceToken = "probe",
    expiresIn = "probe"
  }},
  {name="ap_status", op=3, data={
    ap_role = "probe",
    ap_status = "probe",
    cap_id = 0,
    entry_id = 0,
    entry_name = "probe",
    filter = {},
    freq_name = "probe",
    group_id = 0,
    ip = "192.168.1.1",
    led_status = "probe",
    link_status = "probe",
    mac = "00:11:22:33:44:55",
    model_name = "probe",
    search_name = "probe",
    search_type = "probe",
    search_value = "probe",
    size = 10,
    sort = "probe",
    sort_field = "probe",
    sort_type = "probe",
    ssid = "probe",
    start = 0
  }},
  {name="ap_status_evt", op=2, data={
    entry_id = 0,
    evt = "noop",
    null = "probe"
  }},
  {name="ap_status_radio_info", op=3, data={
    entry_id = 0
  }},
  {name="ap_status_ssid", op=3, data={
    entry_id = 0,
    size = 10,
    start = 0
  }},
  {name="ap_telnet_status_evt", op=2, data={
    entry_id = 0,
    evt = "noop",
    null = "probe"
  }},
  {name="ap_update_token", op=2, data={
    deviceToken = "probe",
    expiresIn = "probe",
    token_str = "probe"
  }},
  {name="ap_vlan_info", op=3, data={
    null = "probe",
    size = 10,
    start = 0
  }},
  {name="apdb_datasync", op=2, data={
    data_msg = "probe",
    len = "probe"
  }},
  {name="aplist_get", op=3, data={}},
  {name="apmng_backup_link", op=2, data={
    backup_ip = "192.168.1.1",
    backup_ip6 = "192.168.1.1",
    enable = 0,
    priority = "probe"
  }},
  {name="apmng_band_navigation", op=2, data={
    ["5g_threshold"] = "probe",
    dif_threshold = "probe",
    enable = 0,
    max_fail_num = "probe"
  }},
  {name="apmngr_apdb_info", op=3, data={{
      firmware_id = 999,
      model_id = 999
    }}},
  {name="apmngr_aplog", op=2, data={
    ac_log_level = "probe",
    ac_log_switch = 0,
    remote_log_level = "probe",
    remote_report_interval = 80,
    remote_server = "probe",
    remote_server_switch = 0
  }},
  {name="apmngr_crashdump", op=2, data={
    enable = 0,
    export_proto = 80,
    gateway_ip = "192.168.1.1",
    server_ip = "192.168.1.1",
    server_port = 80
  }},
  {name="apmngr_cruise_setting", op=2, data={
    enable = 0,
    scan_interval = "probe",
    scan_time = "2026-01-01 00:00:00"
  }},
  {name="apmngr_datasync", op=2, data={
    data_msg = "probe",
    len = "probe"
  }},
  {name="apmngr_entry", op=0, data={
    account_password = "12345678",
    account_username = "probe",
    ap_keep_alive = "probe",
    ap_mesh_switch = 0,
    ap_role = "probe",
    ap_trunk = "probe",
    client_idle = 0,
    client_keep_alive = "probe",
    crashdump_status = "probe",
    entry_id = 0,
    entry_name = "probe",
    entry_type = "probe",
    firmware_id = 0,
    fit_fat_button_status = "probe",
    group_id = 0,
    hardware_ver = "probe",
    lag_mode = "probe",
    lag_phy_list = {},
    lag_phy_num = "probe",
    led = "probe",
    led_close_date = "2026-01-01 00:00:00",
    led_close_time = "2026-01-01 00:00:00",
    led_open_date = "2026-01-01 00:00:00",
    led_open_time = "2026-01-01 00:00:00",
    led_timer_enable = 0,
    led_wifi_sync = "probe",
    mac = "00:11:22:33:44:55",
    model_id = 0,
    new_ap_trunk = "probe",
    offline_selfmanage = "probe",
    password = "12345678",
    phy_wire_vlan_list = {},
    rf_change_enable = 0,
    rf_mode = "probe",
    status = 0,
    telnet_status = "probe",
    username = "probe"
  }},
  {name="apmngr_entry", op=1, data={
    ap = "probe",
    ap_tmp = "probe",
    null = "probe",
    template = "probe"
  }},
  {name="apmngr_entry", op=2, data={
    ap_keep_alive = "probe",
    ap_mesh_switch = 0,
    ap_trunk = "probe",
    cap_id = 0,
    client_idle = 0,
    client_keep_alive = "probe",
    cloud_config_id = 0,
    crashdump_status = "probe",
    entry_id = 0,
    entry_name = "probe",
    entry_type = "probe",
    errno = "probe",
    fit_fat_button_status = "probe",
    lag_mode = "probe",
    lag_phy_list = {},
    lag_phy_num = "probe",
    led = "probe",
    led_close_date = "2026-01-01 00:00:00",
    led_close_time = "2026-01-01 00:00:00",
    led_open_date = "2026-01-01 00:00:00",
    led_open_time = "2026-01-01 00:00:00",
    led_timer_enable = 0,
    led_wifi_sync = "probe",
    mac = "00:11:22:33:44:55",
    model_id = 0,
    multi_id_list = {},
    multi_ids = 0,
    new_ap_trunk = "probe",
    offline_selfmanage = "probe",
    password = "12345678",
    phy_wire_vlan_list = {},
    region_code = "probe",
    replace_mac = "00:11:22:33:44:55",
    rf_change_enable = 0,
    rf_mode = "probe",
    software_ver = "probe",
    telnet_status = "probe",
    username = "probe"
  }},
  {name="apmngr_entry", op=3, data={
    ap_role = "probe",
    condition = "probe",
    entry_type = "probe",
    filters = "probe",
    group_id = 0,
    search_name = "probe",
    search_value = "probe",
    size = 10,
    sort = "probe",
    sort_field = "probe",
    sort_type = "probe",
    start = 0
  }},
  {name="apmngr_entry_authorize", op=2, data={
    entry_id = 0,
    operation = 0
  }},
  {name="apmngr_entry_authorize", op=3, data={
    size = 10,
    start = 0
  }},
  {name="apmngr_entry_backup", op=3, data={}},
  {name="apmngr_entry_copy", op=2, data={
    ap_ids = {},
    copy_ap_id = 0,
    entry_id = 0,
    replace = "probe"
  }},
  {name="apmngr_firm", op=2, data={0}},
  {name="apmngr_global", op=2, data={
    apmngr_status = "probe",
    auto_firm = "probe",
    auto_reboot = "probe",
    reboot_day = "probe",
    reboot_time = "2026-01-01 00:00:00"
  }},
  {name="apmngr_group", op=0, data={
    end_ip = "192.168.1.1",
    entry_name = "probe",
    group_id = 0,
    name = "probe",
    specific_strategy = "probe",
    start_ip = "192.168.1.1",
    strategy_enable = 0
  }},
  {name="apmngr_group", op=1, data={
    group_id = 0
  }},
  {name="apmngr_group", op=2, data={
    end_ip = "192.168.1.1",
    group_id = 0,
    name = "probe",
    specific_strategy = "probe",
    start_ip = "192.168.1.1",
    strategy_enable = 0
  }},
  {name="apmngr_group_join", op=2, data={
    ap_ids = {},
    group_id = 0,
    null = "probe",
    template_ids = 0
  }},
  {name="apmngr_online_model", op=3, data={
    group_id = 0,
    search_name = "probe",
    search_value = "probe",
    size = 10,
    start = 0
  }},
  {name="apmngr_status_backup", op=3, data={}},
  {name="apupd_check_allow_update", op=3, data={
    model_id = 0,
    upgrade_type = "probe"
  }},
  {name="apupd_config", op=2, data={
    state = "probe"
  }},
  {name="apupd_group_delete", op=2, data={
    group_id = 0
  }},
  {name="apupd_image_check", op=3, data={
    file_size = "probe"
  }},
  {name="apupd_large_image_status", op=2, data={
    mac = "00:11:22:33:44:55",
    model_id = 0
  }},
  {name="apupd_large_image_status", op=3, data={
    mac = "00:11:22:33:44:55",
    model_id = 0
  }},
  {name="apupd_log", op=1, data={
    model_id = 0
  }},
  {name="apupd_log", op=3, data={
    ap_role = "probe",
    model_id = 0,
    size = 10,
    start = 0
  }},
  {name="apupd_model", op=0, data={
    ap_list = "probe",
    group_id = 0,
    is_large_fw = "probe",
    is_sys = "probe",
    model_id = 0,
    total_image_piece = "probe",
    total_image_size = "probe",
    total_md5 = "probe",
    upgrade_date = "2026-01-01 00:00:00",
    upgrade_datetime_type = "2026-01-01 00:00:00",
    upgrade_start_time = "2026-01-01 00:00:00",
    upgrade_type = "probe"
  }},
  {name="apupd_model", op=1, data={
    model_id = 0
  }},
  {name="apupd_model", op=2, data={
    auto_to_manual = "probe",
    model_id = 0,
    upgrade_date = "2026-01-01 00:00:00",
    upgrade_datetime_type = "2026-01-01 00:00:00",
    upgrade_start_time = "2026-01-01 00:00:00",
    upgrade_type = "probe"
  }},
  {name="apupd_model", op=3, data={
    is_mesh_device = "probe",
    model_id = 0,
    product_type = "probe",
    size = 10,
    start = 0,
    status = 0,
    upgrade_type = "probe"
  }},
  {name="apupd_status", op=3, data={}},
  {name="apupd_upgrade_status", op=3, data={
    entry_ids = 0
  }},
  {name="apupd_wtp", op=2, data={
    is_large_fw = "probe",
    mac = "00:11:22:33:44:55",
    total_image_piece = "probe",
    total_image_size = "probe",
    total_md5 = "probe",
    upgrade_type = "probe"
  }},
  {name="apupd_wtp", op=3, data={
    ap_role = "probe",
    group_id = 0,
    mac = "00:11:22:33:44:55",
    model_id = 0,
    size = 10,
    start = 0,
    state = "probe"
  }},
  {name="arp_defend_ap", op=2, data={
    ap_id = 0,
    arp_id = 0,
    operation = 0
  }},
  {name="arp_defend_ap", op=3, data={
    group_id = 0,
    limit = 10,
    offset = 0,
    search_name = "probe",
    search_type = "probe",
    search_value = "probe"
  }},
  {name="arp_defend_arp", op=0, data={
    arp_id = 0,
    description = "192.168.1.1",
    ip = "192.168.1.1",
    is_scan_add = "probe",
    mac = "00:11:22:33:44:55"
  }},
  {name="arp_defend_arp", op=1, data={
    arp_id = 0
  }},
  {name="arp_defend_arp", op=2, data={
    arp_id = 0,
    description = "192.168.1.1",
    ip = "192.168.1.1",
    mac = "00:11:22:33:44:55"
  }},
  {name="arp_defend_arp", op=3, data={}},
  {name="arp_defend_do_scan", op=2, data={
    group_id_str = 0
  }},
  {name="arp_defend_scan", op=3, data={
    limit = 10,
    offset = 0,
    search_name = "probe",
    search_value = "probe"
  }},
  {name="arp_defend_setting", op=2, data={
    defend_mode = "probe",
    wired_port_switch = 0,
    wireless_port_switch = 0
  }},
  {name="backup_rf_mngr_entry", op=3, data={}},
  {name="bcast_storm_ctrl", op=2, data={
    arp_limit_type = "probe",
    arp_proxy_switch = 0,
    arp_proxy_to_unicast_switch = 0,
    arp_proxy_type = "probe",
    arp_rate_limit = "probe",
    dhcp_limit_type = "probe",
    dhcp_rate_limit = "probe",
    dhcpv6_limit_type = "probe",
    dhcpv6_rate_limit = "probe",
    enable = 0,
    icmpv6_ns_limit_type = "probe",
    icmpv6_ns_rate_limit = "probe",
    icmpv6_rs_limit_type = "probe",
    icmpv6_rs_rate_limit = "probe",
    igmp_limit_type = "probe",
    igmp_rate_limit = "probe",
    mdns_proxy_switch = 0,
    mdns_proxy_to_unicast_switch = 0,
    nd_proxy_switch = 0,
    nd_proxy_to_unicast_switch = 0,
    nd_proxy_type = "probe",
    other_broadcast_limit_type = "probe",
    other_broadcast_rate_limit = "probe",
    other_multicast_limit_type = "probe",
    other_multicast_rate_limit = "probe",
    proto_list = "probe",
    storm_rate = "probe"
  }},
  {name="bluetooth_network_rule_list", op=0, data={
    ap_ids = {},
    broadcast_channel_set = {},
    broadcast_deduplicate_enable = 0,
    broadcast_filter_data_type = {},
    broadcast_filter_enable = {},
    broadcast_filter_match_data = {},
    broadcast_filter_match_method = "probe",
    group_ids = {},
    gw_work_mode = "probe",
    id = 0,
    mode = 0,
    name = "probe",
    operation_password = "12345678",
    operation_username = "probe",
    rssi_deduplicate_enable = 0,
    rssi_threshold = "probe",
    server_id = 0
  }},
  {name="bluetooth_network_rule_list", op=1, data={
    id = {999}
  }},
  {name="bluetooth_network_rule_list", op=2, data={
    ap_ids = {},
    broadcast_channel_set = {},
    broadcast_deduplicate_enable = 0,
    broadcast_filter_data_type = {},
    broadcast_filter_enable = {},
    broadcast_filter_match_data = {},
    broadcast_filter_match_method = "probe",
    group_ids = {},
    gw_work_mode = "probe",
    id = 0,
    mode = 0,
    name = "probe",
    operation_password = "12345678",
    operation_username = "probe",
    rssi_deduplicate_enable = 0,
    rssi_threshold = "probe",
    server_id = 0
  }},
  {name="bluetooth_network_rule_list", op=3, data={
    id = 0,
    name = "probe",
    size = 10,
    start = 0
  }},
  {name="client_report_switch", op=2, data={
    status = 0
  }},
  {name="client_rssi_data", op=3, data={
    duration = "probe"
  }},
  {name="cloud_mngt_clear_config_id", op=2, data={
    cloud_config_id = 0
  }},
  {name="cloud_mngt_fast_report", op=2, data={
    time_interval = "2026-01-01 00:00:00"
  }},
  {name="cloud_mngt_report_para", op=2, data={
    time_interval = "2026-01-01 00:00:00"
  }},
  {name="cloud_mngt_sync_cloud_config_switch", op=2, data={
    status = 0
  }},
  {name="cloud_mngt_sync_device_config", op=2, data={
    cloud_config_id = 0,
    id = 0
  }},
  {name="cloud_mngt_sync_module_config_report", op=2, data={
    config_list = "probe",
    config_name = "probe",
    module_name = "probe",
    name = "probe"
  }},
  {name="deep_checkup_pkt_bssid_list", op=3, data={
    ["end"] = "probe",
    start = 0
  }},
  {name="deep_checkup_pkt_ssid_list", op=3, data={
    chnl = "probe",
    entry_id = 0
  }},
  {name="deep_checkup_pkt_sta_list", op=3, data={
    ["end"] = "probe",
    start = 0
  }},
  {name="deep_inspection_chnl_usage_list", op=3, data={
    entry_id = 0
  }},
  {name="deep_inspection_multi_chnl_density", op=3, data={
    entry_id = 0
  }},
  {name="deep_inspection_multi_chnl_rssi", op=3, data={
    entry_id = 0
  }},
  {name="deep_inspection_multi_chnl_waterfall", op=3, data={
    ["end"] = "probe",
    entry_id = 0,
    start = 0
  }},
  {name="deep_inspection_selected_chnl_usage", op=3, data={
    chnl = "probe",
    entry_id = 0
  }},
  {name="deep_inspection_status", op=3, data={}},
  {name="dhcpdef_apbind", op=2, data={
    ap_id = 0,
    operation = 0
  }},
  {name="dhcpdef_apbind", op=3, data={
    group_id = 0,
    limit = 10,
    offset = 0,
    search_name = "probe",
    search_type = "probe",
    search_value = "probe"
  }},
  {name="dhcpdef_apbind_svr", op=2, data={
    ap_id = 0,
    operation = 0,
    svr_id = 0
  }},
  {name="dhcpdef_apbind_svr", op=3, data={
    ap_id = 0,
    limit = 10,
    offset = 0,
    search_name = "probe",
    search_value = "probe"
  }},
  {name="dhcpdef_svr", op=0, data={
    addr_type = "probe",
    name = "probe",
    svr_addr = "probe",
    svr_id = 0
  }},
  {name="dhcpdef_svr", op=1, data={
    svr_id = 0
  }},
  {name="dhcpdef_svr", op=2, data={
    addr_type = "probe",
    name = "probe",
    operation = 0,
    svr_addr = "probe",
    svr_id = 0
  }},
  {name="diagnose_global", op=2, data={
    enable = 0,
    telnet_port = 80
  }},
  {name="edca_config", op=3, data={
    ap_id = 0,
    rf_id = 0,
    size = 10,
    start = 0
  }},
  {name="edca_rule", op=0, data={
    ap_be_aifs = "probe",
    ap_be_cwmax = "probe",
    ap_be_cwmin = "probe",
    ap_be_txop = "probe",
    ap_bk_aifs = "probe",
    ap_bk_cwmax = "probe",
    ap_bk_cwmin = "probe",
    ap_bk_txop = "probe",
    ap_id = 0,
    ap_vi_aifs = "probe",
    ap_vi_cwmax = "probe",
    ap_vi_cwmin = "probe",
    ap_vi_txop = "probe",
    ap_vo_aifs = "probe",
    ap_vo_cwmax = "probe",
    ap_vo_cwmin = "probe",
    ap_vo_txop = "probe",
    edca_enable = 0,
    edca_mode = "probe",
    edca_rule_id = 0,
    edca_rule_name = "probe",
    freq_map = "probe",
    group_id = 0,
    reset_edca_default = "probe",
    sta_be_aifs = "probe",
    sta_be_cwmax = "probe",
    sta_be_cwmin = "probe",
    sta_be_txop = "probe",
    sta_bk_aifs = "probe",
    sta_bk_cwmax = "probe",
    sta_bk_cwmin = "probe",
    sta_bk_txop = "probe",
    sta_vi_aifs = "probe",
    sta_vi_cwmax = "probe",
    sta_vi_cwmin = "probe",
    sta_vi_txop = "probe",
    sta_vo_aifs = "probe",
    sta_vo_cwmax = "probe",
    sta_vo_cwmin = "probe",
    sta_vo_txop = "probe",
    static_edca_type = "probe",
    wmm = 0
  }},
  {name="edca_rule", op=1, data={
    ids = {}
  }},
  {name="edca_rule", op=2, data={
    ap_be_aifs = "probe",
    ap_be_cwmax = "probe",
    ap_be_cwmin = "probe",
    ap_be_txop = "probe",
    ap_bk_aifs = "probe",
    ap_bk_cwmax = "probe",
    ap_bk_cwmin = "probe",
    ap_bk_txop = "probe",
    ap_id = 0,
    ap_vi_aifs = "probe",
    ap_vi_cwmax = "probe",
    ap_vi_cwmin = "probe",
    ap_vi_txop = "probe",
    ap_vo_aifs = "probe",
    ap_vo_cwmax = "probe",
    ap_vo_cwmin = "probe",
    ap_vo_txop = "probe",
    edca_enable = 0,
    edca_mode = "probe",
    edca_rule_id = 0,
    edca_rule_name = "probe",
    freq_map = "probe",
    group_id = 0,
    reset_edca_default = "probe",
    sta_be_aifs = "probe",
    sta_be_cwmax = "probe",
    sta_be_cwmin = "probe",
    sta_be_txop = "probe",
    sta_bk_aifs = "probe",
    sta_bk_cwmax = "probe",
    sta_bk_cwmin = "probe",
    sta_bk_txop = "probe",
    sta_vi_aifs = "probe",
    sta_vi_cwmax = "probe",
    sta_vi_cwmin = "probe",
    sta_vi_txop = "probe",
    sta_vo_aifs = "probe",
    sta_vo_cwmax = "probe",
    sta_vo_cwmin = "probe",
    sta_vo_txop = "probe",
    static_edca_type = "probe",
    wmm = 0
  }},
  {name="edca_rule", op=3, data={
    edca_rule_name = "probe",
    ids = {},
    size = 10,
    start = 0
  }},
  {name="ftp_server_list", op=0, data={
    ap_ids = {},
    group_ids = {},
    rule_id = 0,
    user_name = "probe",
    user_password = "12345678"
  }},
  {name="ftp_server_list", op=1, data={
    rule_id = {999}
  }},
  {name="ftp_server_list", op=2, data={
    ap_ids = {},
    group_ids = {},
    rule_id = 0,
    user_name = "probe",
    user_password = "12345678"
  }},
  {name="ftp_server_list", op=3, data={
    size = 10,
    start = 0
  }},
  {name="ftp_status_list", op=3, data={
    rule_id = {999}
  }},
  {name="get_deep_inspection_scan_mode_change", op=3, data={
    entry_id = 0
  }},
  {name="get_deep_inspection_setting", op=3, data={}},
  {name="host_info", op=3, data={
    ap_role = "probe",
    auth_type = "probe",
    bind_enable = 0,
    data_type = "probe",
    mac = "00:11:22:33:44:55",
    mac_array = {},
    mac_count = "probe",
    operation_type = "probe",
    search_name = "probe",
    search_type = "probe",
    search_value = "probe",
    select_filter = "probe",
    size = 10,
    sort = "probe",
    sort_field = "probe",
    sort_type = "probe",
    start = 0
  }},
  {name="host_info_back", op=3, data={}},
  {name="iot_server_list", op=0, data={
    ca_file_path = "probe",
    client_id = 0,
    id = 0,
    is_encrypt = "probe",
    password = "12345678",
    protocol = 0,
    server_addr = "probe",
    server_port = 80,
    server_type = "probe",
    topic_comment = {},
    topic_data_type = {},
    topic_detail = "probe",
    topic_feature = "probe",
    username = "probe"
  }},
  {name="iot_server_list", op=1, data={
    id = {999}
  }},
  {name="iot_server_list", op=2, data={
    ca_file_path = "probe",
    client_id = 0,
    id = 0,
    is_encrypt = "probe",
    password = "12345678",
    protocol = 0,
    server_addr = "probe",
    server_port = 80,
    server_type = "probe",
    topic_comment = {},
    topic_data_type = {},
    topic_detail = "probe",
    topic_feature = "probe",
    username = "probe"
  }},
  {name="iot_server_list", op=3, data={
    id = 0
  }},
  {name="jcs_radio_mode_entry", op=3, data={
    ap_ids = {},
    filter = {},
    firmware_id = 0,
    model_id = 0,
    size = 10,
    start = 0
  }},
  {name="local_nms_switch", op=2, data={
    status = 0,
    type = 0
  }},
  {name="local_server_set", op=2, data={
    ip = "192.168.1.1",
    local_server = "probe",
    port = 80
  }},
  {name="macauth_blacklist", op=3, data={}},
  {name="macauth_group", op=0, data={
    auth_type = "probe",
    bind_vlan_type = 1,
    enable = 0,
    id = 0,
    mac_id_map = {},
    name = "probe",
    note = "probe",
    old_serv_id_map = {},
    old_ssid = "probe",
    old_vlan = 1,
    operation = 0,
    serv_id_map = {},
    type = 0,
    vlan = 1,
    vlan_pool_id = 1
  }},
  {name="macauth_group", op=1, data={
    id = 0,
    vlan = 1
  }},
  {name="macauth_group", op=2, data={
    auth_type = "probe",
    bind_vlan_type = 1,
    enable = 0,
    id = 0,
    mac_id_map = {},
    name = "probe",
    note = "probe",
    old_serv_id_map = {},
    old_ssid = "probe",
    old_vlan = 1,
    operation = 0,
    serv_id_map = {},
    type = 0,
    vlan = 1,
    vlan_pool_id = 1
  }},
  {name="macauth_group", op=3, data={
    type = 0
  }},
  {name="macauth_group_for_ssid", op=0, data={
    auth_type = "probe",
    bind_vlan_type = 1,
    enable = 0,
    id = 0,
    mac_id_map = {},
    name = "probe",
    note = "probe",
    old_serv_id_map = {},
    old_ssid = "probe",
    old_vlan = 1,
    operation = 0,
    serv_id_map = {},
    type = 0,
    vlan = 1,
    vlan_pool_id = 1
  }},
  {name="macauth_group_for_ssid", op=1, data={
    id = 0,
    name = "probe",
    serv_id_map = {},
    type = 0,
    value = "probe"
  }},
  {name="macauth_group_for_ssid", op=2, data={
    auth_type = "probe",
    bind_vlan_type = 1,
    enable = 0,
    id = 0,
    mac_id_map = {},
    name = "probe",
    note = "probe",
    old_serv_id_map = {},
    old_ssid = "probe",
    old_vlan = 1,
    operation = 0,
    serv_id_map = {},
    type = 0,
    vlan = 1,
    vlan_pool_id = 1
  }},
  {name="macauth_mac", op=0, data={
    id = 0,
    mac = "00:11:22:33:44:55",
    name = "probe"
  }},
  {name="macauth_mac", op=1, data={
    id = 0
  }},
  {name="macauth_mac", op=2, data={
    id = 0,
    mac = "00:11:22:33:44:55",
    name = "probe"
  }},
  {name="macauth_mac", op=3, data={}},
  {name="macauth_mac_for_group", op=1, data={
    id = 0
  }},
  {name="macauth_type", op=2, data={
    auth_mode = "probe",
    type = 0
  }},
  {name="macauth_vlan_str_check", op=3, data={
    id = 0,
    vlan_id_str = 1
  }},
  {name="nego_del", op=1, data={}},
  {name="notify_unbind", op=2, data={}},
  {name="nsa_user_backup", op=3, data={}},
  {name="port_list", op=2, data={
    ap_id_array = 0,
    ap_mac_array = "probe",
    count = 10,
    enable = 0,
    port_id_array = 80,
    pvid = 0
  }},
  {name="port_list", op=3, data={
    ap_id = 0,
    ap_mac = "00:11:22:33:44:55",
    id = 0
  }},
  {name="rdmngr_datasync", op=2, data={
    data_msg = "probe",
    len = "probe"
  }},
  {name="report_debug_switch_set", op=2, data={
    status = 0
  }},
  {name="rf_mngr", op=2, data={
    airtime = 0,
    antenna = "probe",
    ap_be_aifs = "probe",
    ap_be_cwmax = "probe",
    ap_be_cwmin = "probe",
    ap_be_txop = "probe",
    ap_bk_aifs = "probe",
    ap_bk_cwmax = "probe",
    ap_bk_cwmin = "probe",
    ap_bk_txop = "probe",
    ap_vi_aifs = "probe",
    ap_vi_cwmax = "probe",
    ap_vi_cwmin = "probe",
    ap_vi_txop = "probe",
    ap_vo_aifs = "probe",
    ap_vo_cwmax = "probe",
    ap_vo_cwmin = "probe",
    ap_vo_txop = "probe",
    bandwidth = 0,
    bcn_intvl = "probe",
    brd_probe = 0,
    channel = "probe",
    downlink_mumimo = "probe",
    downlink_ofdma = "probe",
    dtim_prd = "probe",
    edca_enable = 0,
    edca_mode = "probe",
    enable_6g = "probe",
    enable_6g_psc = "probe",
    force_modify = "probe",
    frag_thr = "probe",
    freq_band = "probe",
    gi_mode = "probe",
    manage_frame_rate = "probe",
    max_usr = "probe",
    mode = 0,
    multi_id_list = {},
    mutex_channel = "probe",
    operation = 0,
    power_level = "probe",
    rail_high_speed_mode_switch = 0,
    reject_diff = "probe",
    reject_enable = 0,
    reject_limit = "probe",
    reset_edca_default = "probe",
    rf_check_circle = "probe",
    rf_chnl_dcs = "probe",
    rf_chnl_occup_threshold = "probe",
    rf_chnl_reselect = "probe",
    rf_chnl_tolerance = "probe",
    rf_name = "probe",
    rf_online_switch = 0,
    rf_state = "probe",
    rssi_kick = "probe",
    rssi_kick_val = "probe",
    rssi_restrict = "probe",
    rssi_restrict_val = "probe",
    rts_thr = "probe",
    short_gi = 0,
    sta_be_aifs = "probe",
    sta_be_cwmax = "probe",
    sta_be_cwmin = "probe",
    sta_be_txop = "probe",
    sta_bk_aifs = "probe",
    sta_bk_cwmax = "probe",
    sta_bk_cwmin = "probe",
    sta_bk_txop = "probe",
    sta_vi_aifs = "probe",
    sta_vi_cwmax = "probe",
    sta_vi_cwmin = "probe",
    sta_vi_txop = "probe",
    sta_vo_aifs = "probe",
    sta_vo_cwmax = "probe",
    sta_vo_cwmin = "probe",
    sta_vo_txop = "probe",
    static_edca_type = "probe",
    twt = "probe",
    uplink_mumimo = "probe",
    uplink_ofdma = "probe",
    wmm = 0
  }},
  {name="rf_mngr", op=3, data={
    ap_role = "probe",
    ap_status = "probe",
    group_id = 0,
    search_cond = "probe",
    search_name = "probe",
    search_value = "probe",
    size = 10,
    start = 0
  }},
  {name="rf_mngr_entry", op=3, data={
    rf_id = 0
  }},
  {name="rf_mngr_template_export", op=3, data={}},
  {name="roam_exist_unsupport_ap", op=3, data={
    exist_unsupport_wireless_network_mode_ap = 80
  }},
  {name="roam_wireless_network_mode", op=2, data={
    wireless_network_mode = "probe"
  }},
  {name="roam_wireless_network_mode", op=3, data={
    wireless_network_mode = "probe"
  }},
  {name="send_tdcp_test", op=2, data={
    tdcp_msg = "probe"
  }},
  {name="sensor_discover_trigger", op=2, data={
    action = "stop"
  }},
  {name="sensor_global", op=2, data={
    backhaul_enable = 0,
    backhaul_encode = "probe",
    backhaul_key = "probe",
    backhaul_ssid = "probe",
    backhaul_ssidbrd = 0,
    backhaul_wserv_id = 0,
    enable = 0,
    force_set = "probe",
    wserv_cfg_change = "probe"
  }},
  {name="sensor_list_added", op=3, data={
    ["end"] = "probe",
    start = 0
  }},
  {name="sensor_manage_status", op=3, data={}},
  {name="sensor_test_case_list", op=0, data={
    test_case_name = "cap_probe",
    change_id = 0,
    sch_period = 0,
    sch_time = 0,
    sch_type = 0,
    rssi_threshold = -95,
    group_id = {},
    join_test_sensor = {},
    ssid_info = {},
    service = {{
        ser_name = "dns",
        params = {{
            ser_index = 0
          }}
      }}
  }},
  {name="sensor_test_case_list", op=1, data={
    test_case_id = {}
  }},
  {name="sensor_test_case_list", op=2, data={
    test_case_id = 0,
    test_case_name = "cap_probe",
    change_id = 0,
    sch_period = 0,
    sch_time = 0,
    sch_type = 0,
    rssi_threshold = -95,
    group_id = {},
    join_test_sensor = {},
    ssid_info = {},
    service = {{
        ser_name = "dns",
        params = {{
            ser_index = 0
          }}
      }}
  }},
  {name="sensor_test_detail_result", op=3, data={
    bssid = 0,
    ser_index = 0,
    test_case_id = {},
    test_type = "probe"
  }},
  {name="sensor_test_digest", op=3, data={}},
  {name="sensor_test_group_delete_event_handle", op=2, data={
    group_id = 0
  }},
  {name="sensor_test_result", op=3, data={
    ["end"] = "probe",
    result = 0,
    sch_start_time = "2026-01-01 00:00:00",
    sensor_name = "probe",
    ser_index = 0,
    start = 0,
    test_case_id = {},
    test_type = "probe"
  }},
  {name="sensor_test_ssid_list", op=3, data={
    ["end"] = "probe",
    group_list = "probe",
    rssi_threshold = "probe",
    sensor_list = "probe",
    start = 0
  }},
  {name="sensor_test_summary", op=3, data={
    ser_index = 0,
    test_case_id = {},
    test_type = "probe"
  }},
  {name="sensor_test_summary_new", op=3, data={
    test_case_id = {}
  }},
  {name="sensor_test_wserv_delete_event_handle", op=2, data={
    serv_id = 0
  }},
  {name="set_deep_inspection_scan_mode_change", op=2, data={
    chnl = "probe",
    entry_id = 0,
    scan_mode = "probe"
  }},
  {name="set_deep_inspection_setting", op=2, data={
    deep_inspection_set = "probe",
    entry_id = 0,
    inspection_band = "probe",
    inspection_item = "probe",
    switch = 0,
    use_previous_setting = "probe"
  }},
  {name="start_report_sub_device_info", op=2, data={
    sub_device_mac_list = "probe"
  }},
  {name="systime", op=2, data={}},
  {name="target_ap", op=2, data={
    is_all = "probe",
    is_set_group = "probe",
    target_ap_file = "probe",
    tftp = "probe"
  }},
  {name="target_ap", op=3, data={}},
  {name="tdcp_passthrough", op=2, data={
    tdcp_msg = "probe"
  }},
  {name="uac_lldp", op=2, data={
    is_first = "probe"
  }},
  {name="uac_lldp", op=3, data={
    is_first = "probe"
  }},
  {name="uac_nms_report_switch", op=2, data={
    enable = 0
  }},
  {name="udbg", op=2, data={
    cmd = "probe"
  }},
  {name="unsupport_ap_get", op=3, data={}},
  {name="usb_settings", op=2, data={
    ap_ids = {},
    enable = 0,
    group_ids = {}
  }},
  {name="usb_settings", op=3, data={}},
  {name="vlan_id_str_check", op=3, data={
    id = 0,
    vlan_id_str = 1
  }},
  {name="vlan_pool", op=0, data={
    id = 0,
    name = "probe",
    vlan_id_str = 1
  }},
  {name="vlan_pool", op=1, data={
    id = 0
  }},
  {name="vlan_pool", op=2, data={
    id = 0,
    name = "probe",
    vlan_id_str = 1
  }},
  {name="vlan_pool_del_check", op=3, data={
    id = 0
  }},
  {name="whitelist", op=0, data={
    mac = "00:11:22:33:44:55",
    ssid = "probe",
    ssid_encode = 0
  }},
  {name="whitelist", op=1, data={
    whitelist_ids = {}
  }},
  {name="whitelist", op=3, data={
    size = 10,
    start = 0
  }},
  {name="wips_event_info", op=2, data={
    operation = 0,
    wips_info_ids = "192.168.1.1"
  }},
  {name="wips_event_info", op=3, data={
    entry_name = "probe",
    size = 10,
    start = 0,
    wips_info_id = "192.168.1.1",
    wips_threat_classname = "192.168.1.1",
    wips_threat_level = "192.168.1.1"
  }},
  {name="wips_statistics", op=3, data={
    type = 0
  }},
  {name="wips_statistics_num", op=3, data={}},
  {name="wportal", op=0, data={
    account_port = 80,
    admin_dn = "probe",
    admin_passwd = "12345678",
    auth_port = 80,
    auth_type = "probe",
    base_dn = "probe",
    cloud_portal_url = "http://192.168.1.1/",
    cmcc_ac_name = "probe",
    cmcc_auth_server_type = "probe",
    cmcc_mac_auth = "probe",
    cmcc_url = "http://192.168.1.1/",
    datasync_data_type = "probe",
    datasync_op_type = "probe",
    dst_ip = "192.168.1.1",
    dst_ip_mask = "probe",
    dst_port_end = 80,
    dst_port_start = 80,
    entry_id = 0,
    fail_id = 0,
    fail_url = "http://192.168.1.1/",
    id = 0,
    index = 0,
    match_type = "probe",
    method = "probe",
    name = "probe",
    nas_identifier = 0,
    nas_ip = "192.168.1.1",
    portal_page_switch = 0,
    protocol = 0,
    radius_auth_type = "probe",
    remote_mac_auth = "probe",
    remote_url = "http://192.168.1.1/",
    retry_count = "probe",
    retry_interval = "probe",
    serv_id = 0,
    server_addr = "probe",
    server_name = "probe",
    session_timeout = "2026-01-01 00:00:00",
    share_key = "12345678",
    src_ip = "192.168.1.1",
    src_ip_mask = "probe",
    src_mac = "00:11:22:33:44:55",
    src_port_end = 80,
    src_port_start = 80,
    src_vlan = 1,
    type = 0,
    url = "http://192.168.1.1/",
    user_filter = "probe",
    user_passwd_filter = "12345678",
    vlan_id = 1
  }},
  {name="wportal", op=1, data={
    auth_mode = "probe",
    auth_type = "probe",
    bas_identifier = 0,
    change = "probe",
    cmccServerIp = "probe",
    count = 10,
    del_mode = "probe",
    del_user = "probe",
    entry_id = 0,
    free_auth_id = 0,
    index = 0,
    interface = "probe",
    ip = "192.168.1.1",
    key = "12345678",
    mac = "00:11:22:33:44:55",
    match_type = "probe",
    method = "probe",
    name = "probe",
    portal_port = 80,
    serialNo = "probe",
    serv_id = 0,
    sso_enable = 0,
    sso_port = 80,
    sso_server = "probe",
    sso_type = "probe",
    type = 0,
    useChap = "probe",
    username = "probe",
    version = "probe",
    vlan_id = 1
  }},
  {name="wportal", op=2, data={
    account_port = 80,
    admin_dn = "probe",
    admin_passwd = "12345678",
    age_enable = 0,
    age_time = "2026-01-01 00:00:00",
    ageing_enable = 0,
    ageing_time = "2026-01-01 00:00:00",
    auth_mode = "probe",
    auth_port = 80,
    auth_type = "probe",
    auto = "probe",
    base_dn = "probe",
    cloud_portal_url = "http://192.168.1.1/",
    cmcc_ac_name = "probe",
    cmcc_auth_server_type = "probe",
    cmcc_mac_auth = "probe",
    cmcc_port = 80,
    cmcc_portal_port = 80,
    cmcc_url = "http://192.168.1.1/",
    del_mode = "probe",
    entry_id = 0,
    fail_id = 0,
    fail_url = "http://192.168.1.1/",
    https_enable = 0,
    id = 0,
    index = 0,
    key = "12345678",
    method = "probe",
    nas_identifier = 0,
    nas_ip = "192.168.1.1",
    old_vlan_id = 1,
    portal_page_switch = 0,
    portal_port = 80,
    radius_auth_type = "probe",
    remote_mac_auth = "probe",
    remote_url = "http://192.168.1.1/",
    retry_count = "probe",
    retry_interval = "probe",
    serv_id = 0,
    server_addr = "probe",
    server_name = "probe",
    session_timeout = "2026-01-01 00:00:00",
    share_key = "12345678",
    sso_config = {},
    sso_enable = 0,
    sso_port = 80,
    sso_server = "probe",
    sso_type = "probe",
    type = 0,
    user_filter = "probe",
    user_passwd_filter = "12345678",
    value = "probe",
    vlan_id = 1
  }},
  {name="wportal", op=3, data={
    ip = "192.168.1.1",
    mac = "00:11:22:33:44:55",
    portal_id = 80,
    search = "probe",
    search_arg = {
      auth_type = "probe",
      search_name = "probe",
      search_value = "probe",
      value_type = "probe",
      write_to_file = "probe"
    },
    serv_id = 0,
    size = 10,
    sort = "probe",
    start = 0,
    type = 0,
    vlan = 1
  }},
  {name="wportal_backup", op=3, data={}},
  {name="wportal_nsa_sync", op=2, data={}},
  {name="wportal_user_data", op=3, data={
    duration = "probe"
  }},
  {name="wserv_global", op=2, data={
    igmp_2g_rate = "probe",
    igmp_2g_rate_type = "probe",
    igmp_5g_rate = "probe",
    igmp_5g_rate_type = "probe",
    igmp_drop_unknown = "probe",
    igmp_max_resp_time = "2026-01-01 00:00:00",
    igmp_multi_to_unicast = "probe",
    igmp_query_interval = "probe",
    igmp_snooping_enable = 0,
    is_set_snp = "probe"
  }},
  {name="wservice", op=0, data={
    auth = 0,
    auto_bind = 0,
    bw_ctrl_enable = 0,
    bw_ctrl_mode = "probe",
    central_forward_switch = 0,
    cipher = "192.168.1.1",
    default_bind_freq = "probe",
    default_bind_vlan = 1,
    desc = "probe",
    down_limit = "probe",
    enable = 0,
    encryption = 0,
    igmp_2g_rate = "probe",
    igmp_2g_rate_type = "probe",
    igmp_5g_rate = "probe",
    igmp_5g_rate_type = "probe",
    igmp_drop_unknown = "probe",
    igmp_max_resp_time = "2026-01-01 00:00:00",
    igmp_multi_to_unicast = "probe",
    igmp_query_interval = "probe",
    igmp_query_switch = 0,
    igmp_snooping_enable = 0,
    igmp_snooping_switch = 0,
    isolate = 0,
    key = "12345678",
    key_update_intv = "2026-01-01 00:00:00",
    mlo_switch = 0,
    ppsk_group = "probe",
    radius_acct_port = 80,
    radius_auth_channel = "probe",
    radius_ip = "192.168.1.1",
    radius_nas_id = 0,
    radius_port = 80,
    radius_pwd = "12345678",
    radius_session_timeout = "2026-01-01 00:00:00",
    radius_vlan_enable = 0,
    serv_id = 0,
    ssid = "probe",
    ssid_code_type = 0,
    ssid_id = 0,
    ssidbrd = 0,
    time_switch = 0,
    up_limit = "probe"
  }},
  {name="wservice", op=1, data={
    serv_id = 0
  }},
  {name="wservice", op=2, data={
    auth = 0,
    auto_bind = 0,
    bw_ctrl_enable = 0,
    bw_ctrl_mode = "probe",
    central_forward_switch = 0,
    cipher = "192.168.1.1",
    default_bind_freq = "probe",
    default_bind_vlan = 1,
    desc = "probe",
    down_limit = "probe",
    enable = 0,
    encryption = 0,
    igmp_2g_rate = "probe",
    igmp_2g_rate_type = "probe",
    igmp_5g_rate = "probe",
    igmp_5g_rate_type = "probe",
    igmp_drop_unknown = "probe",
    igmp_max_resp_time = "2026-01-01 00:00:00",
    igmp_multi_to_unicast = "probe",
    igmp_query_interval = "probe",
    igmp_query_switch = 0,
    igmp_snooping_enable = 0,
    igmp_snooping_switch = 0,
    isolate = 0,
    key = "12345678",
    key_update_intv = "2026-01-01 00:00:00",
    mlo_switch = 0,
    operation = 0,
    ppsk_group = "probe",
    radio_id = 0,
    radius_acct_port = 80,
    radius_auth_channel = "probe",
    radius_ip = "192.168.1.1",
    radius_nas_id = 0,
    radius_port = 80,
    radius_pwd = "12345678",
    radius_session_timeout = "2026-01-01 00:00:00",
    radius_vlan_enable = 0,
    serv_id = 0,
    ssid = "probe",
    ssid_code_type = 0,
    ssid_id = 0,
    ssidbrd = 0,
    time_switch = 0,
    up_limit = "probe",
    vlan_id = 1
  }},
  {name="wservice", op=3, data={
    group_id = 0,
    limit = 10,
    offset = 0,
    radio_id = 0,
    search_cond = "probe",
    search_name = "probe",
    search_value = "probe",
    serv_id = 0
  }},
  {name="wservice_ip", op=0, data={
    enable = 0,
    id = 0,
    ip_addr = "192.168.1.1",
    relay = 0
  }},
  {name="wservice_ip", op=1, data={
    id = 0
  }},
  {name="wservice_ip", op=2, data={
    enable = 0,
    id = 0,
    ip_addr = "192.168.1.1",
    is_set_enable = 0,
    relay = 0
  }},
  {name="wsta_bind_info", op=0, data={
    bind_enable = 0,
    bind_radio_id = 0,
    down_limit = "probe",
    force_bind_enable = 0,
    mac = "00:11:22:33:44:55",
    time_obj = {},
    up_limit = "probe"
  }},
  {name="wsta_bind_info", op=1, data={
    mac = "00:11:22:33:44:55"
  }},
  {name="wsta_bind_info", op=2, data={
    bind_enable = 0,
    bind_radio_id = 0,
    down_limit = "probe",
    force_bind_enable = 0,
    mac = "00:11:22:33:44:55",
    time_obj = {},
    up_limit = "probe"
  }},
  {name="wsta_bind_info_net_rule", op=2, data={
    enable = 0,
    mac = "00:11:22:33:44:55"
  }},
  {name="wsta_iso_group", op=0, data={
    enable = 0,
    group_ids = {},
    id = 0,
    isolate_type = "probe",
    isolation_switch = 0,
    name = "probe",
    ssid_list = {},
    white_list = {}
  }},
  {name="wsta_iso_group", op=1, data={
    id = 0
  }},
  {name="wsta_iso_group", op=2, data={
    enable = 0,
    group_ids = {},
    id = 0,
    isolate_type = "probe",
    isolation_switch = 0,
    name = "probe",
    ssid_list = {},
    white_list = {}
  }},
  {name="wsta_iso_group", op=3, data={
    id = 0,
    name = "probe",
    size = 10,
    start = 0
  }},
  {name="wstation", op=1, data={
    entry_id = 0,
    mac = "00:11:22:33:44:55"
  }},
  {name="wstation", op=2, data={
    overload_threshold = "probe"
  }},
  {name="wstation", op=3, data={
    ap_role = "probe",
    auth_type = "probe",
    bind_enable = 0,
    filter = {
      auth_type = "probe"
    },
    freq_name = "probe",
    group_id = 0,
    search_name = "probe",
    search_value = "probe",
    size = 10,
    sort = "probe",
    sort_field = "probe",
    sort_type = "probe",
    start = 0
  }},
  {name="wstation_backup", op=3, data={}},
  {name="wstation_disconnect", op=2, data={
    mac = "00:11:22:33:44:55"
  }},
  {name="wstation_mac", op=1, data={
    entry_id = 0,
    mac = "00:11:22:33:44:55"
  }},
  {name="wstation_peer_mac", op=3, data={
    mac = "00:11:22:33:44:55"
  }},
  {name="wstation_recognize", op=2, data={
    brand = "probe",
    operating_system = "probe",
    prohibit_access_switch = 0
  }},
}
