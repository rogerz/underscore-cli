#include <jansson.h>

typedef struct {
/*> _.each(props, function(prop) { */  /*= prop.type_t */ /*= prop.name */;
/*> }); */} /*= module.config_t */;

typedef struct {
  /*= module.config_t */ /*= vars.config */;
  json_t */*= vars.json */;
  const char */*= vars.path */;
} /*= module.type_t */;

typedef (*/*= module.callback_t */)(/*= module.config_t */ *);

/*= module.type_t */ /*= module.var */;
/*= module.callback_t */ */*= module.update_cb */ = NULL;
/*= module.callback_t */ */*= module.init_cb */ = NULL;

int /*= module.config_init */(void) {
  /*= module.type_t */ */*= module.ptr */ = &/*= module.var */;
  /*= module.config_t */ */*= vars.config_p */ = /*= module.ptr */->/*= vars.config */;
  json_t */*= vars.json_default */, */*= vars.json */;

  /*> _.each(props, function(prop) { *//*= vars.config_p */->/*= prop.name */ = /*= prop.default */;
  /*> }); */
  /*= vars.json_default */ = json_pack(
				       "/*= module.pack_str */"
				       /*> _.each(props, function(prop) {*/, "/*= prop.name */", /*= vars.config_p */->/*= prop.name */
				       /*> }); */);

  /*= vars.json */ = /*= config.get */(/*= module.ptr */->/*= vars.path */);

  if (/*= vars.json */) {
    json_object_deep_update(/*= vars.json */, /*= vars.json_default */, /*= MACRO.INIT_UPDATE_FLAG */);
  } else {
    /*= vars.json */ = /*= vars.json_default */;
    /*= config.set */(/*= module.ptr */->/*= vars.path */, /*= vars.json */);
  }

  /*= module.ptr */->/*= vars.json */ = json_incref(/*= vars.json */);

  json_decref(/*= vars.json_default */);

  if (/*= module.init_cb */) {
    /*= module.init_cb */(/*= vars.config_p */);
  }

  return 0;
}

int /*= module.config_load */(json_t */*= vars.json */) {
  /*= module.config_t */ */*= vars.config_p */ = &/*= module.var */./*= vars.config*/;
  const json_t *json = /*= module.var */./*= vars.json */;
  json_unpack(/*= vars.json */, 
	      "/*= module.unpack_str */"
	      /*> _.each(props, function(prop) {*/, "/*= prop.name */", &/*= vars.config_p */->/*= prop.name */,
	      /*> }); */);

  if (/*= module.update_cb */) {
    /*= module.update_cb */(/*= vars.config_p */);
  }

  return 0;
}

const /*= module.config_t */ */*= module.config_get */(void) {
  return &/*= module.var*/.config;
}
