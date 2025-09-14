/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpinguet <mpinguet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 19:52:30 by mpinguet          #+#    #+#             */
/*   Updated: 2025/09/14 19:52:30 by mpinguet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

static int  count_words(const char *s, char c)
{
    int count = 0;
    int in_word = 0;

    while (*s)
    {
        if (*s != c && !in_word)
        {
            in_word = 1;
            count++;
        }
        else if (*s == c)
            in_word = 0;
        s++;
    }
    return (count);
}

static char *word_dup(const char *s, int start, int end)
{
    char *word;
    int   i = 0;

    word = malloc((end - start + 1) * sizeof(char));
    if (!word)
        return (NULL);
    while (start < end)
        word[i++] = s[start++];
    word[i] = '\0';
    return (word);
}

static void free_all(char **arr, int i)
{
    while (i-- > 0)
        free(arr[i]);
    free(arr);
}

char    **ft_split(char const *s, char c)
{
    char    **result;
    int     i = 0, j = 0, start;

    if (!s)
        return (NULL);
    result = malloc((count_words(s, c) + 1) * sizeof(char *));
    if (!result)
        return (NULL);
    while (s[i])
    {
        if (s[i] != c)
        {
            start = i;
            while (s[i] && s[i] != c)
                i++;
            result[j] = word_dup(s, start, i);
            if (!result[j])
                return (free_all(result, j), NULL);
            j++;
        }
        else
            i++;
    }
    result[j] = NULL;
    return (result);
}
