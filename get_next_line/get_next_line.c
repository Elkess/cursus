/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melkess <melkess@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 11:46:59 by melkess           #+#    #+#             */
/*   Updated: 2024/11/30 16:46:31 by melkess          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *aid(char *line)
{
	while (*line != '\n' && *line != '\0')
		line++;
	if (*line == '\n')
		return (ft_strdup(line + 1, 0));
	return NULL;
}

char	*get_next_line(int fd)
{
	static char	*temp;
	char		*bayd;
	char		*line;
	int			running;

	if (BUFFER_SIZE <= 0 || fd < 0 || BUFFER_SIZE > __INT_MAX__)
		return (NULL);
	line = malloc(BUFFER_SIZE +1);
	if (!line)
		return (NULL);
	running = 1;
	bayd = NULL;
	while (running && read(fd, line, BUFFER_SIZE) > 0)
	{
		running = is_there_newline(line);
		line[BUFFER_SIZE] = '\0';
		temp = ft_strjoin(temp, line);
		if (temp)
			bayd = temp;
		if (running == 0)
				temp = aid(line);
		}
	free(line);
	return (bayd);
}
/*
void ff()
{
	system("leaks a.out");
}
int main(void)
{
	// atexit(ff);
	int fd ;
	char *s ;
	fd = open("../files/file.txt", O_RDWR);

	while ((s = get_next_line(fd)))
	{
		printf("%s", s);
		free(s);
	}
	return 0;
}
*/


/*
void test_file(const char *filename)
{
    int fd = open(filename, O_RDONLY);
    if (fd < 0)
    {
        perror("Error opening file");
        return;
    }

    printf("Testing file: %s\n", filename);
    char *line;
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("Line: %s", line); // Lines include '\n' except at EOF
        free(line);
    }
    close(fd);
    printf("\nFinished testing file: %s\n\n", filename);
}

void test_stdin()
{
    printf("Testing standard input (Type lines and press Ctrl+D to end):\n");
    char *line;
    while ((line = get_next_line(STDIN_FILENO)) != NULL)
    {
        printf("Line: %s", line);
        free(line);
    }
    printf("\nFinished testing standard input.\n\n");
}

void test_edge_cases()
{
    printf("Testing edge cases:\n");

    // Test with an invalid file descriptor
    char *line = get_next_line(-1);
    if (line == NULL)
        printf("Test with invalid file descriptor: PASSED (returned NULL)\n");
    else
    {
        printf("Test with invalid file descriptor: FAILED\n");
        free(line);
    }

    // Test with a very large buffer size (adjust buffer size during compilation)
    int fd = open("large_test_file.txt", O_RDONLY);
    if (fd >= 0)
    {
        printf("Testing with a large file:\n");
        while ((line = get_next_line(fd)) != NULL)
        {
            printf("%s", line);
            free(line);
        }
        close(fd);
    }
    else
        printf("Skipping large file test (file not found).\n");

    printf("Finished edge case testing.\n\n");
}

void test_multiple_file_descriptors()
{
    printf("Testing multiple file descriptors:\n");
    int fd1 = open("file1.txt", O_RDONLY);
    int fd2 = open("file2.txt", O_RDONLY);

    if (fd1 < 0 || fd2 < 0)
    {
        perror("Error opening files for multiple FD test");
        if (fd1 >= 0) close(fd1);
        if (fd2 >= 0) close(fd2);
        return;
    }

    char *line1 = get_next_line(fd1);
    char *line2 = get_next_line(fd2);

    while (line1 != NULL || line2 != NULL)
    {
        if (line1)
        {
            printf("File1: %s", line1);
            free(line1);
            line1 = get_next_line(fd1);
        }
        if (line2)
        {
            printf("File2: %s", line2);
            free(line2);
            line2 = get_next_line(fd2);
        }
    }

    close(fd1);
    close(fd2);
    printf("Finished multiple file descriptor testing.\n\n");
}

int main(int argc, char **argv)
{
    // Test with provided files
    if (argc > 1)
    {
        for (int i = 1; i < argc; i++)
            test_file(argv[i]);
    }
    else
        printf("No files provided for testing.\n");

    // Test standard input
    test_stdin();

    // Test edge cases
    test_edge_cases();

    // Test multiple file descriptors
    test_multiple_file_descriptors();

    printf("All tests completed.\n");
    return 0;
}

*/
