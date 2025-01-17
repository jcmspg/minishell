/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joamiran <joamiran@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 18:07:52 by joamiran          #+#    #+#             */
/*   Updated: 2024/12/19 19:42:12 by joamiran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

// parsing the line into tokens
void	parse_line(t_shell *shell)
{
    char **tokens;

    if (!shell->line)
        return ;
    tokens = ft_parse_split(shell->line);
    if (!tokens)
        return ;

    shell->tokens = tokens; 
}


// parsing to make tokens so we can later parse the tokens into commands
void	parse_tokens(t_shell *shell) // this function is not complete
{
    // for now it just prints the tokens
    int i;

    i = 0;
    while (shell->tokens[i])
    {
        ft_printf("Token %d: %s\n", i, shell->tokens[i]);
        i++;
    }
}

// parse the line and tokens
void	parse(t_shell *shell)
{
    parse_line(shell);          // parse the line
    if (shell->tokens)
        parse_tokens(shell);    // parse the tokens
    else
        ft_printf_fd(2, "Error"); // print error message
}
