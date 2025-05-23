/* vim:set et sw=2 cin cino=t0,f0,(0,{s,>2s,n-s,^-s,e2s: */

/*
 * Copyright © 2019 Collabora Ltd.
 * Copyright © 2024 Red Hat, Inc.
 *
 * SPDX-License-Identifier: LGPL-2.0+
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library. If not, see <https://www.gnu.org/licenses/>.
 */

#pragma once

#include "ostree-sign.h"

G_BEGIN_DECLS

#define OSTREE_TYPE_SIGN_SPKI (_ostree_sign_spki_get_type ())

_OSTREE_PUBLIC
G_DECLARE_FINAL_TYPE (OstreeSignSpki, _ostree_sign_spki, OSTREE, SIGN_SPKI, GObject)

gboolean ostree_sign_spki_data (OstreeSign *self, GBytes *data, GBytes **signature,
                                GCancellable *cancellable, GError **error);

gboolean ostree_sign_spki_data_verify (OstreeSign *self, GBytes *data, GVariant *signatures,
                                       char **out_success_message, GError **error);

const gchar *ostree_sign_spki_get_name (OstreeSign *self);
const gchar *ostree_sign_spki_metadata_key (OstreeSign *self);
const gchar *ostree_sign_spki_metadata_format (OstreeSign *self);

gboolean ostree_sign_spki_clear_keys (OstreeSign *self, GError **error);

gboolean ostree_sign_spki_set_sk (OstreeSign *self, GVariant *secret_key, GError **error);

gboolean ostree_sign_spki_set_pk (OstreeSign *self, GVariant *public_key, GError **error);

gboolean ostree_sign_spki_add_pk (OstreeSign *self, GVariant *public_key, GError **error);

gboolean ostree_sign_spki_load_pk (OstreeSign *self, GVariant *options, GError **error);

G_END_DECLS
