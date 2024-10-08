/* SPDX-License-Identifier: LGPL-2.1-or-later */
#pragma once

#include <inttypes.h>

#include "conf-parser.h"
#include "in-addr-util.h"
#include "networkd-util.h"

typedef struct Link Link;
typedef struct Manager Manager;
typedef struct Network Network;

typedef struct AddressLabel {
        Manager *manager;
        Network *network;
        ConfigSection *section;

        uint32_t label;
        struct in6_addr prefix;
        unsigned char prefixlen;
        bool prefix_set;
} AddressLabel;

AddressLabel *address_label_free(AddressLabel *label);

void network_drop_invalid_address_labels(Network *network);
void manager_drop_invalid_address_labels(Manager *manager);

int link_request_static_address_labels(Link *link);
int manager_request_static_address_labels(Manager *manager);

CONFIG_PARSER_PROTOTYPE(config_parse_address_label);
CONFIG_PARSER_PROTOTYPE(config_parse_address_label_prefix);
