// This file was generated by gir (https://github.com/gtk-rs/gir)
// from gir-files
// DO NOT EDIT

use crate::{ffi};
use glib::{translate::*};

glib::wrapper! {
    #[derive(Debug, PartialEq, Eq, PartialOrd, Ord, Hash)]
    pub struct Remote(Shared<ffi::OstreeRemote>);

    match fn {
        ref => |ptr| ffi::ostree_remote_ref(ptr),
        unref => |ptr| ffi::ostree_remote_unref(ptr),
        type_ => || ffi::ostree_remote_get_type(),
    }
}

impl Remote {
    #[doc(alias = "ostree_remote_get_name")]
    #[doc(alias = "get_name")]
    pub fn name(&self) -> glib::GString {
        unsafe {
            from_glib_none(ffi::ostree_remote_get_name(self.to_glib_none().0))
        }
    }

    #[doc(alias = "ostree_remote_get_url")]
    #[doc(alias = "get_url")]
    pub fn url(&self) -> Option<glib::GString> {
        unsafe {
            from_glib_full(ffi::ostree_remote_get_url(self.to_glib_none().0))
        }
    }
}

impl std::fmt::Display for Remote {
    #[inline]
    fn fmt(&self, f: &mut std::fmt::Formatter) -> std::fmt::Result {
        f.write_str(&self.name())
    }
}
