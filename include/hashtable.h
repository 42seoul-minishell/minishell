/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashtable.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bolee <bolee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 13:35:00 by bolee             #+#    #+#             */
/*   Updated: 2022/12/13 13:35:01 by bolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HASHTABLE_H
# define HASHTABLE_H

# include "struct.h"

/* in ../src/internal/hashmap/ */
/* create.c */
t_ht_item		*create_ht_item(char *key, char *value);
t_hashtable		*create_hashtable(size_t size);

/* insert.c */
void			hash_insert(t_ht_item *new_item, t_hashtable *table);

/* utils.c */
char			*get_key_from_env(char *str);
char			*get_value_from_env(char *env);
void			display_hashtable(t_hashtable *table);
void			prevent_collision(t_hashtable *table, size_t hash, \
							t_ht_item *new_item);

/* hashtable.c */
t_hashtable		*parse_env_to_hashtable(char **env);
size_t			hash_index(char *key, size_t size);

/* delete.c */
void			delete_item(t_ht_item *item);
void			delete_table(t_hashtable *table);
void			delete_item_by_key(t_hashtable *table, char *key);

/* search.c */
char			*search(t_hashtable *table, char *key);

/* update.c */
void			update_value(t_hashtable *table, char *key, char *value);

#endif
